stop(){
    echo "kill rip_topologia2 routers.."
    tmux kill-session -t FREERTR;
    echo "byebye.."
    exit 0;
}

stop
