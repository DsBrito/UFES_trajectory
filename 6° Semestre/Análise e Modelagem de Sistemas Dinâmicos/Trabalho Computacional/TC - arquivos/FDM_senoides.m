%                                                                         %
% =========================================================================
%                                                                         %
% Lab 4 - Principios Comunicações I - Aplicações Modulação AM             %
%             ----  Multiplexação FDM  ----                               %
%                                                                         %
% by Prof. Jair Silva                                                     %
%                                                                         %
% =========================================================================

% Inicialização
clc, clear all, close all


% ===============  Dados de Simulação  ===================================
Fs      = 1e6;      % Taxa de amostragem dos  sinais em banda passante 
Fc1     = 0.2e6;    % Frequencia de operação do primeiro sinal 
Fc2     = 0.3e6;    % Frequencia de operação do segundo sinal
Fc3     = 0.4e6;   % Frequencia de operação do terceiro sinal
snr     = 100;      % Relação Sinal-Ruído
fcorte1 = 0.55;      % Primeira Freq. corte do filtro de DEMULTIPLEXAÇÃO  
fcorte2 = 0.65;     % Segunda  Freq. corte do filtro de DEMULTIPLEXAÇÃO 
ordem   = 40;       % Ordem do filtro passa faixa de recepção
% =========================================================================

% Cálculos Preliminares
ta  = 1/Fs;            % Periodo de amostragem dos sinais em banda base
tam = 2048;            % Tamanho dos vetores 
t  = (0:ta:tam*ta).';  % Cria o novo vetor tempo já em banda passante

% --------- Primeira parte - Gera os sinais a serem multiplexados --------
% Primeiro sinal em Banda Base (Fonte I)
fm1 = 1000;             % Frequencia central do primeiro sinal (Banda Base)
m1  = sin(2*pi*fm1*t);  % primeiro sinal a ser multiplexado 

% Segundo sinal em Banda Base (Fonte II)
fm2 = 2000;             % Frequencia central do segundo sinal (Banda Base)
m2  = sin(2*pi*fm2*t);  % segundo sinal a ser multiplexado 

% Terceiro sinal em Banda Base (Fonte III)
fm3 = 3000;             % Frequencia central do segundo sinal (Banda Base)
m3  = sin(2*pi*fm3*t);  % segundo sinal a ser multiplexado 
% ------------------------------------------------------------------------


% ---------- Segunda Parte: Modulação dos sinais de mensagem -------------
m1_mod = ssbmod(m1,Fc1,Fs);   % Modula o primeiro sinal
m2_mod = ssbmod(m2,Fc2,Fs);   % Modula o segundo sinal
m3_mod = ssbmod(m3,Fc3,Fs);   % Modula o terceiro sinal
% ------------------------------------------------------------------------


%  ---------------- Terceira Parte - Multiplexação -----------------------
sinal_mux = m1_mod + m2_mod + m3_mod;  % sinal multiplexado
% ------------------------------------------------------------------------


%#########################################################################
%############### Quarta Parte - Canal Ruidoso ############################

sinal_mux_ruidoso = awgn(sinal_mux,snr,'measured');

%#########################################################################
%#########################################################################


% --------  Quinta Parte - Demultiplexação usando Filtro Passa Faixa ----- 
%fcorte1 = 0.45;      % Primeira Freq. corte do filtro de DEMULTIPLEXAÇÃO  
h = fir1(ordem,[fcorte1 fcorte2]);            % Cria o filtro passa banda 
%h = fir1(ordem,fcorte1,'low');            % Cria o filtro passa banda  
figure(6), freqz(h,1,512)                    % Plota a resposta do filtro
sinal_demux = filter(h,1,sinal_mux_ruidoso);  % Filtra/demultiplexa
% ------------------------------------------------------------------------


% ------------- Sexta Parte - Demodulação (SSB) --------------------------

m_demod = ssbdemod(sinal_demux,Fc2,Fs);   % Modula o segundo sinal
% ------------------------------------------------------------------------


% .................... Fim da Simulação ..................................


% ........... Plota alguns Gráficos ...................................... 
% Plota o sinal de mensagem m1 no dominio do tempo e da frequencia
figure(1)         
subplot(3,1,1)
plot(t,m1,'b'), grid, 
title ('Fonte I'); xlabel('tempo [s]'), ylabel('ampl. [u.a.]')

[M1,m1n,f1,df1] = FFT_pot2(m1.',ta);  % Determina o espectro
figure(2), plot(f1,10*log10(fftshift(abs(M1))),'b'), grid
title ('Espectro de Potência em Banda Base');
xlabel('Frequência[Hz]'), ylabel('PSD [dB/Hz]')

% Plota o sinal de mensagem m2 no dominio do tempo e da frequencia
figure(1)         
subplot(3,1,2)
plot(t,m2,'g'), grid
title ('Fonte II'); xlabel('tempo [s]'), ylabel('ampl. [u.a.]')

[M2,m2n,f2,df2] = FFT_pot2(m2.',ta);   % determina o espectro
figure(2), hold on, plot(f2,10*log10(fftshift(abs(M2))),'g'), grid

% Plota o sinal de mensagem m2 no dominio do tempo e da frequencia
figure(1)         
subplot(3,1,3)
plot(t,m3,'r'), grid
title ('Fonte III'); xlabel('tempo [s]'), ylabel('ampl. [u.a.]')

[M3,m3n,f3,df3] = FFT_pot2(m3.',ta);   % determina o espectro
figure(2), hold on, plot(f3,10*log10(fftshift(abs(M3))),'r'), grid


% Plota os sinais modulados no dominio do tempo e da frequencia
figure(3)
subplot(3,1,1), plot(t,m1_mod,'b'), grid, title ('Fonte I Modulada')
subplot(3,1,2), plot(t,m2_mod,'g'), grid, title ('Fonte II Modulada');
subplot(3,1,3), plot(t,m3_mod,'r'), grid, title ('Fonte III Modulada');
xlabel('tempo [s]')

figure(4)
[M1_mod,m1n_mod,f1_mod,df1_mod] = FFT_pot2(m1_mod.',ta);   % Espectro
[M2_mod,m2n_mod,f2_mod,df2_mod] = FFT_pot2(m2_mod.',ta);   % Espectro
[M3_mod,m3n_mod,f3_mod,df3_mod] = FFT_pot2(m3_mod.',ta);   % Espectro
plot(f1_mod,10*log10(fftshift(abs(M1_mod))),'b'), grid, hold on
plot(f2_mod,10*log10(fftshift(abs(M2_mod))),'g'), grid, hold on
plot(f3_mod,10*log10(fftshift(abs(M3_mod))),'r'), grid
title ('Espectro de Potência em Banda Passante (SSB)');
xlabel('Frequência[Hz]'), ylabel('PSD [dB/Hz]')
legend('Fonte I Modulada', 'Fonte II Modulada', 'Fonte III Modulada')


% Plota o resultado da multiplexação no tempo e na frequencia 
figure(5) 
subplot(4,1,1), plot(t,sinal_mux,'b'), grid, title ('sinal MULTIPLEXADO')
xlabel('tempo [s]'), ylabel('ampl. [u.a.]')

[SMUX,smux,f1_mux,df1_mux] = FFT_pot2(sinal_mux.',ta);   % Espectro
subplot(4,1,2), plot(f1_mux,10*log10(fftshift(abs(SMUX))),'b')
title ('Espectro de Potência do sinal MULTIPLEXADO');
xlabel('Frequência[Hz]'), ylabel('PSD [dB/Hz]')

% Plota o resultado da multiplexação com ruído no tempo e na frequencia 
figure(5) 
subplot(4,1,3), plot(t,sinal_mux_ruidoso,'r'), grid, title ('sinal MULTIPLEXADO com ruído')
xlabel('tempo [s]'), ylabel('ampl. [u.a.]')

[SMUX_ruido,smux_ruido,f1_mux,df1_mux] = FFT_pot2(sinal_mux_ruidoso.',ta);   % Espectro
subplot(4,1,4), plot(f1_mux,10*log10(fftshift(abs(SMUX_ruido))),'r')
title ('Espectro de Potência do sinal MULTIPLEXADO com Ruído');
xlabel('Frequência[Hz]'), ylabel('PSD [dB/Hz]')

% Plota a resposta do filtro
figure(6), freqz(h,1,512)    

% Plota o resultado da demultiplexação no tempo e na frequencia 
figure(7) 
subplot(2,1,1), plot(t,sinal_demux,'k'), grid, title ('sinal DEMULTIPLEXADO')
xlabel('tempo [s]'), ylabel('ampl. [u.a.]')

[SDEMUX,smux,f2_demux,df2_demux] = FFT_pot2(sinal_demux.',ta);   % Espectro
subplot(2,1,2), plot(f1_mux,10*log10(fftshift(abs(SDEMUX))),'k')
title ('Espectro de Potência do sinal DEMULTIPLEXADO');
xlabel('Frequência[Hz]'), ylabel('PSD [dB/Hz]')

% Plota o resultado da demodulação no tempo e na frequencia 
figure(8) 
subplot(2,1,1), plot(t,m_demod,'b'), grid, title ('sinal DEMODULADO')
xlabel('tempo [s]'), ylabel('ampl. [u.a.]')

[SDEMOD,sdemod,f_demod,df_demod] = FFT_pot2(m_demod.',ta);   % Espectro
subplot(2,1,2), plot(f_demod,10*log10(fftshift(abs(SDEMOD))),'b')
title ('Espectro de Potência do sinal DEMODULADO');
xlabel('Frequência[Hz]'), ylabel('PSD [dB/Hz]')

% Comparação em figuras
figure(9)
subplot(2,1,1), plot(t,m_demod,'b'), grid 
hold on, plot(t,m2,'r--')
title ('Comparando os sinais'), xlabel('tempo [s]'), ylabel('ampl. [u.a.]')

subplot(2,1,2), plot(f_demod,10*log10(fftshift(abs(SDEMOD))),'b-'), grid
hold on, plot(f1,10*log10(fftshift(abs(M2))),'r--')
title ('Comparando os Espectros dos sinais Gerado e Recuperado');
xlabel('Frequência[Hz]'), ylabel('PSD [dB/Hz]')

% =========================================================================
%