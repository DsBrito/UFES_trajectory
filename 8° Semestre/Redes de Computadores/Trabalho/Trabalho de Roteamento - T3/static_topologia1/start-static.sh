#!/bin/bash

start_static(){
    RTR=rtr.jar
    HWSW=hw-sw/dsbrito_

    # Executa os roteadores
    tmux new-session -d -s rare 'java -jar '$RTR' routersc '$HWSW'r1-hw.txt '$HWSW'r1-sw.txt'
    tmux split-window -v -t 0 -p 50
    tmux send 'java -jar '$RTR' routersc '$HWSW'r2-hw.txt '$HWSW'r2-sw.txt' ENTER;
    tmux split-window -h -t 0 -p 50
    tmux send 'java -jar '$RTR' routersc '$HWSW'r3-hw.txt '$HWSW'r3-sw.txt' ENTER;
    tmux split-window -h -t 0 -p 50
    tmux send 'java -jar '$RTR' routersc '$HWSW'r4-hw.txt '$HWSW'r4-sw.txt' ENTER;
    tmux split-window -h -t 0 -p 50
    tmux send 'java -jar '$RTR' routersc '$HWSW'r5-hw.txt '$HWSW'r5-sw.txt' ENTER;
    tmux select-layout tiled;

    echo -ne "Initializing routers (10 seconds).."
    sleep 10 #se caso aparecer "Unable to connect to remote host: Connection refused" aumente o tempo de sleep (depende de cada PC)

    tmux new-session -d -s telnet 'telnet localhost 26001'
    tmux split-window -v -t 0 -p 50
    tmux send 'telnet localhost 26002' ENTER;
    tmux split-window -h -t 0 -p 50
    tmux send 'telnet localhost 26003' ENTER;
    tmux split-window -h -t 0 -p 50
    tmux send 'telnet localhost 26004' ENTER;
    tmux split-window -h -t 0 -p 50
    tmux send 'telnet localhost 26005' ENTER;
    tmux select-layout tiled;

    tmux a;
}

start_static