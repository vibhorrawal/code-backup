`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/26/2019 01:57:28 PM
// Design Name: 
// Module Name: test
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


module test(
    output y,
    input i0,i1,i2,i3,s0,s1
    );
    wire w0, w1, w2, w3;
    and(w0, i0, ~s0, ~s1);
    and(w1, i1, s0, ~s1);
    and(w2, i2, ~s0, s1);
    and(w3, i3, s0, s1);
    or(y,w0,w1,w2,w3);
endmodule
