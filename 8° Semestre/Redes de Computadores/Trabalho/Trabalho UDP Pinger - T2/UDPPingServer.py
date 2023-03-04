import random
from socket import *
import time

recieve_host = 'localhost'
recieve_port = 30000


#recieve_port = 54321


serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind((recieve_host, recieve_port))


simulate_packet_loss = True
sleep_for_rand_response_times = True
simulate_protocol_error = True
simulate_delay_send = True
def get_time():
    return int(round(time.time() * 1000))


msg_ = None
addr = None
delay = False
while True:


   try:
      message, address = serverSocket.recvfrom(1024)
      #print(message)
      message = message.decode()
      print (f"Recieve: {str(message)}")


      '''if sleep_for_rand_response_times:
         min_sleep = 0.2
         max_sleep = 1.0
         time.sleep(random.uniform(min_sleep, max_sleep))
         if simulate_packet_loss:
            if random.randint(0, 10) < 2:
               print ('Dropped, lol')
               continue
      el'''




      m1 = message[0:5]
      m2 = message[5:6]
      m3 = message[6:10]
      m4 = message[10:40]


      if simulate_packet_loss and int(m1) != 8 and int(m1) != 9:
        if random.randint(0, 10) < 1:
            print(message)
            print ('Simulating packet loss')
            continue


      m1 = message[0:5]
      m2 = message[5:6]
      m3 = message[6:10]
      m4 = message[10:40]


      print(f'RECEIVED: {message}')


      if m2 == '0':
         m2 = '1'
      else:
         serverSocket.sendto(message.encode('utf-8'), address)
         print ('Dropped: ping/pong error.')
         continue


      if simulate_protocol_error and  int(m1) != 8:
         if random.randint(0, 10) < 2:
            pass
            #m1 = '00087'
            #m1.rjust(5, "0")
            #print('Simulating sequence error')
         elif random.randint(0, 10) < 2:
            m2 = 'A'
            print('Simulating Ping/Pong error')
         elif random.randint(0, 10) < 2:
            m3 = '0000'
            print('Simulating Timestamp error')


      print(f'Number: {len(m1)}/{m1}  0/1: {len(m2)}/{m2} timestamp: {len(m3)}/{m3} message: {len(m4)}/{m4}')


      message = f'{m1}{m2}{m3}{m4}'
      if int(m1) < 5 and not delay and simulate_delay_send:
         if random.randint(0, 10) < 3:
            msg_ = message
            addr = address
            delay = True
            print('Simulating packet delay ')
            continue
      if int(m1) == 8 and delay and simulate_delay_send:
         serverSocket.sendto(msg_.encode('utf-8'), addr)
         print(f'Sending packet {msg_}')
         time.sleep(0.2)


      serverSocket.sendto(message.encode('utf-8'), address)
      print (f'Send: {message} ')
   except e:
      print(f'eroor {e}')



      