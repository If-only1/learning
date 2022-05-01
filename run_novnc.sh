rm -rf /tmp/.X1-lock 
rm -rf /tmp/.X11-unix/X1   
vncserver -kill :1
vncserver  :1
/root/noVNC/utils/novnc_proxy --vnc localhost:5901 
