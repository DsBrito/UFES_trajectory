
#Disciplina: Redes de Computadores
#Código: 
#Prof. Magnos Martinello

#Trabalho UDP Pinger - Programação em Socket
#Autor: DIONATAS SANTOS BRITO
from socket import *
from statistics import stdev
import time
  
# host = meu host
host = '127.0.0.1'
port = 30000

# Variáveis de Controle
sent_packets = 0
received_packets = 0
rtt_timelist = []
total_time = 0
 
# Criando um socket UDP do cliente
clientSocket = socket(AF_INET, SOCK_DGRAM)
clientSocket.settimeout(2)



message = "@Dionatas_Santos_Brito" #5 - 1 - 4 - 22 =32 Bytes
#[00000][0/1][----][----------------------]
#Exemplos de mensagem 
#0000114057dionatas_brito = 24 Bytes
#0000110000dionatas_santos_brito = 31 Bytes
#0000914263dionatasS_dionatas_santos_brit = 40 Bytes (ele corta a mensagem pois excedeu os 40 Bytes do pacote )


#Criando o protocolo
#Numero de Sequencia = 5 Bytes
#Tipo da requisição (ping/pong) = 0/1 Byte
#TimesStamp (unidade en mili-segundos) = 4 Bytes
#Mensagem do Pacote = 40 Bytes 

def message_test(send_packets, receive_packets):
  
  #Teste de recebimento de pacote
  rpm1 = receive_packets[0:5]   #(5-0) =5 Bytes = numero
  rpm2 = receive_packets[5:6]   #(6-1) =5 Byte = identificador  ping ou pong
  rpm3 = receive_packets[6:10]  #(10-6) =4 Bytes = timestamp
  rpm4 = receive_packets[10:40] #(40-10) =30 Bytes

#Teste de emvio de pacote
  spm1 = send_packets[0:5]   #(5-0) Bytes
  spm2 = send_packets[5:6]   #(6-1) Byte
  spm3 = send_packets[6:10]  #(10-6) Bytes
  spm4 = send_packets[10:40] #(40-10) Bytes
  
  #Controle de pacote (Máximo/Até 40 pacotes)
  #Somente se Pacote X Enviado e Pacote X Recebido forem iguais, será confirmado o recebimento dele.
  if len(receive_packets) != 40: #até 40 packets
    return False
  elif rpm2 != '1':  #ping (se for eh um erro de protocolo)
    return False
  elif rpm1 != spm1:
    return False
  elif rpm4 != spm4:
    return False
  elif rpm3 != spm3:
    return False
  return True


#Controle de Tempo de Envio/Recebimento
for i in range(0, 10):  #o servidor foi setado com um buffer de tamanho 10
  rtt = time.time_ns()
  if i == 0:
    total_time = time.time_ns() #tempo total em ns
  
  number = str(i).rjust(5,'0') #5 Bytes
  timestamp = str(int(rtt / 1000000) % 10000).rjust(4,'0') #4 Bytes
  fix_message = str(message).ljust(30,'\0') #até 30 Bytes
  packtet = number + '0' + timestamp + fix_message  #escrita do protocolo number + 0/1 + timestamp + mensagem

  # enviando um pacote
  clientSocket.sendto(packtet.encode(), (host, port)) # pacote -> (host,porta)
  sent_packets += 1 #incrementa a contagem dos pacotes 

#Controle Perda, Atraso e Validez de pacote
  try:
    data, server = clientSocket.recvfrom(1024)

    receive_packets = data.decode()
    rpm1 = receive_packets[0:5]  #recebendo numero
    spm1 = packtet[0:5]           #enviando numero

    #Caso receba algum pacote atrasado irá entrar no while
    while int(rpm1) < int(spm1): 
      data, server = clientSocket.recvfrom(1024)
      receive_packets = data.decode()
      rpm1 = receive_packets[0:5]
    
    rtt = time.time_ns() - rtt #calculando o tempo
    rtt = rtt / 1000000

  #Caso o pacote seja Inválido, irá entrar nessa condição.
    if(message_test(packtet, receive_packets) is False):
      print('Invalid package')
      continue

    #Incrementando o pacote recebido
    rtt_timelist.append(rtt)
    print(receive_packets)
    received_packets += 1

  #Caso o pacote alcance o limite de tempo, ele será descartado/perdido
  except:
    print('Lost packet [timeout]')

total_time = time.time_ns() - total_time
total_time = total_time / 1000000 # transformando o  total_time para mili-segundos



#Mensagem Final

lost_packets = (100 - received_packets/sent_packets*100)
time = total_time
rtt_min=min(rtt_timelist)
rtt_avg=sum(rtt_timelist)/len(rtt_timelist)
rtt_max = max(rtt_timelist)
rtt_mdev = stdev(rtt_timelist)
if received_packets == 0:
  print('No packet received')

else:
  result = f"{sent_packets} packets transmitted, {received_packets} received, {lost_packets}% packet lost, time {total_time:.2f}ms rtt min/avg/max/mdev = {rtt_min:.4f}/{rtt_avg:.4f}/{rtt_max:.4f}/{rtt_mdev:.4f} ms"

  print(result)