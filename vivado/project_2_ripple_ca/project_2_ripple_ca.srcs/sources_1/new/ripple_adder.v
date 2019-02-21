`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/20/2019 05:52:20 AM
// Design Name: 
// Module Name: ripple_adder
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


module ripple_adder(

    output [4:0] out,
    input [3:0] a,
    input [3:0] b
    );
    reg cin = 0;
    wire w0,w1,w2;
    adder adder0(out[0],w0,a[0],b[0],cin);
    adder adder1(out[1],w1,a[1],b[1],w0);
    adder adder2(out[2],w2,a[2],b[2],w1);
    adder adder3(out[3],out[4],a[3],b[3],w2);
    
endmodule
