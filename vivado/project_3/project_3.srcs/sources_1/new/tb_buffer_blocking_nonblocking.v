`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/27/2019 06:24:26 AM
// Design Name: 
// Module Name: tb_buffer_blocking_nonblocking
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module tb_buffer_blocking_nonblocking(
    );
    reg a = 0;
    wire [6:0] o;
    buffer_blocking_nonblocking b1(a,o[0],o[1],o[2],o[3],o[4],o[5]);
    
    initial
    begin
    #10 // at time : 10
    
    a = 1;
    #10;   
    
    a = 0;
    #10;
    
    a = 1;
    #3;
    
    a = 0;
    #3;
    
    a = 1;
    #9;
    
    a = 0;
    #15;
    end
endmodule
