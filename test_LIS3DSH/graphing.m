clear all;
clc;
close all;


s=serialport("COM7",9600);
configureTerminator(s,"CR/LF");
flush(s);
s.UserData = struct("x",[],"t1",1,"y",[],"t2",1,"z",[],"t3",1);

configureCallback(s,"terminator",@readSerialData)





function readSerialData(src,~)    
    data = readline(src);
    accel = strsplit(data, ',');
    
    src.UserData.x(end+1) = str2double(accel(1));
    src.UserData.y(end+1) = str2double(accel(2));
    src.UserData.z(end+1) = str2double(accel(3));
    
    src.UserData.Count = src.UserData.t1 + 1;
    
    hold on
    plot(src.UserData.x(2:end),'r');
    hold on
    plot(src.UserData.y(2:end),'g');
    hold on
    plot(src.UserData.z(2:end),'b');
       
end

