`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/20/2019 06:10:27 AM
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
    output s,
    output c,
    input a,
    input b,
    input c_in
    );

    wire w1,w2,w3;
    
    xor(w1,a,b);
    xor(s,w1,c_in);
    
    and(w2,a,b);
    and(w3,w1,c_in);

    or(c,w2,w3);
endmodule
