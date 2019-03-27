`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/27/2019 05:45:10 AM
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
    
    wire w1, w2,w3;
    
    xor(w1, a, b);
    xor(sum, w1, c);
    
    and(w2, a, b);
    and(w3, c, w1);
    
    or(carry, w3, w2);
    
endmodule
