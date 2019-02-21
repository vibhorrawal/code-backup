`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/20/2019 06:13:14 AM
// Design Name: 
// Module Name: cla
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


module cla(
    output [4:0] out_result,
    input [3:0] in_a,
    input [3:0] in_b
    );
    
    wire [4:0] w_C;
    wire [3:0] w_G, w_P, w_SUM;
    
    assign w_C[0] = 0;
    full_adder full_adder_bit_0 (.s(w_SUM[0]),.c(),.a(in_a[0]),.b(in_b[0]),.c_in(w_C[0]));
    full_adder full_adder_bit_1 (.s(w_SUM[1]),.c(),.a(in_a[1]),.b(in_b[1]),.c_in(w_C[1]));
    full_adder full_adder_bit_2 (.s(w_SUM[2]),.c(),.a(in_a[2]),.b(in_b[2]),.c_in(w_C[2]));
    full_adder full_adder_bit_3 (.s(w_SUM[3]),.c(),.a(in_a[3]),.b(in_b[3]),.c_in(w_C[3]));
    
    // creating the generate (G) terms: Gi = Ai * Bi;
    assign w_G[0] = in_a[0] & in_b[0];
    assign w_G[1] = in_a[1] & in_b[1];    
    assign w_G[2] = in_a[2] & in_b[2];
    assign w_G[3] = in_a[3] & in_b[3];
    
    // creating the propagate terms: Pi = Ai + Bi
    assign w_P[0] = in_a[0] | in_b[0];
    assign w_P[1] = in_a[1] | in_b[1];
    assign w_P[2] = in_a[2] | in_b[2];
    assign w_P[3] = in_a[3] | in_b[3];
    
    // creating the carry Terms:
    assign w_C[1] = w_G[0] | (w_P[0] & w_C[0]);
    assign w_C[2] = w_G[1] | (w_P[1] & w_C[1]);
    assign w_C[3] = w_G[2] | (w_P[2] & w_C[2]);
    assign w_C[4] = w_G[3] | (w_P[3] & w_C[3]);
    
    assign out_result = {w_C[4], w_SUM};
    
endmodule
