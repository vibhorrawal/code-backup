`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/27/2019 05:51:47 AM
// Design Name: 
// Module Name: rca
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


module rca(
    output  [4:0] out,
    input [3:0] a,
    input [3:0] b
    );
    
    wire c1,c2,c3;
    
    full_adder fa0(out[0], c1, a[0],b[0],0);
    full_adder fa1(out[1],c2,a[1],b[1],c1);
    full_adder fa2(out[2],c3,a[2],b[2],c2);
    full_adder fa3(out[3],out[4],a[3],b[3],c3);
endmodule
