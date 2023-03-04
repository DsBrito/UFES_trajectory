stop_static(){
    echo "kill static_topologia1 routers.."
    tmux kill-window -t rare
    tmux kill-window -t telnet
    echo "byebye.."
    exit 0;

}
stop_static