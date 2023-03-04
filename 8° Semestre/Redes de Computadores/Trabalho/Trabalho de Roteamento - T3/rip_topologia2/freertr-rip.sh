#!/bin/bash


    #default
    #rtr
    RTR=rtr.jar
    Clock=0

    #hardware
    HW_prefix="dsbrito_r"
    HW_suffix="-hw.txt"
    HW_file=$1
    HW_files_count=4


    #software
    SW_prefix="dsbrito_r"
    SW_suffix="-sw.txt"
    SW_file=$2
    SW_files_count=4

    #mesage
    usage() { echo "Usage: $0 [-r <FreeRouter JAR path>] [-d <HW and SW Files path/dir> ]" 1>&2;
    echo "Usage: $0 [-h ] for more help" 1>&2; exit 1; }

    #clock set
    set_clock_true(){
        echo "Clock enabled..."
        Clock=$((1))
    }



    #read flags
    options='r:d:p:s:x:chk'
    while getopts $options flag
    do
        case "${flag}" in
            r) RTR=${OPTARG};;
            d) HWSW=${OPTARG};;
            p) HW_prefix=${OPTARG}; SW_prefix=${OPTARG};;
            s) HW_suffix=${OPTARG};;
            x) SW_suffix=${OPTARG};;
            c) set_clock_true;;
            h) help_script;;
            *) usage;;
        esac
    done



    #start routers
    start_routers(){
        echo "Creating tmux panels..."
        if (($Clock))
        then
            #run tmux
            tmux new-session -d -s FREERTR >/dev/null

            tmux rename-window -t FREERTR:0 'main'
            tmux splitw -h -p 90 -t FREERTR:0.0
            
            let n=$HW_files_count
            for ((i = 1; i < $HW_files_count; i++ ));
            do
                let divisor=$((100 - 100/n))
                n=$((n-1))
                tmux splitw -v -p $(($divisor)) -t FREERTR:0.$(($i));
            done

            #echo "----------------------------------------"
            echo "Starting routers..."
            for ((i = 1; i <= $HW_files_count; i++ )); 
            do
                HW_file="$HWSW$HW_prefix$i$HW_suffix"
                SW_file="$HWSW$SW_prefix$i$SW_suffix"


                tmux send-keys -t FREERTR:0.$(($i)) "java -jar $RTR routersc $HW_file $SW_file" Enter;
            done

            tmux send-keys -t FREERTR:0.0 'tmux clock -t FREERTR:0.0' Enter;
            tmux select-pane -t FREERTR:0.$(($HW_files_count));

        else
            #run tmux
            tmux new-session -d -s FREERTR >/dev/null
            tmux rename-window -t FREERTR:0 'main'

            let n=$HW_files_count
            for ((i = 0; i < $HW_files_count-1; i++ ));
            do
                let divisor=$((100 - 100/n))
                n=$((n-1))
                tmux splitw -v -p $(($divisor)) -t FREERTR:0.$(($i));
            done

            echo "Starting routers..."
            for ((i = 1; i <= $HW_files_count; i++ )); 
            do 
                HW_file="$HWSW$HW_prefix$i$HW_suffix"
                SW_file="$HWSW$SW_prefix$i$SW_suffix"


                tmux send-keys -t FREERTR:0.$(($i-1)) "java -jar $RTR routersc $HW_file $SW_file" Enter;
            done
        fi


        tmux select-layout tiled

        echo "Done."
    }

    open_tmux(){
        echo -ne "Opening tmux in 3.."
        sleep 1
        echo -ne "2.."
        sleep 0.6
        echo -ne "1.."
        sleep 0.6
        tmux a -t FREERTR
    }

    start_routers
    open_tmux
