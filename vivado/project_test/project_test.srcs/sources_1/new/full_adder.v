`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/26/2019 05:07:07 PM
// Design Name: 
// Module Name: full_adder
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


module full_adder(
    output sum,
    output carry,
    input a,
    input b,
    input c
    );
    wire w0, w1, w2;
    xor(w0, a, b);
    xor(sum, w0, c);
    and(w1, w0, c);
    and(w2, a, b);
    or(carry, w1, w2);
endmodule
