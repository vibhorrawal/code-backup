`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/26/2019 07:09:52 PM
// Design Name: 
// Module Name: s_test
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



`include "full_adder.v"
module s_test (input [3:0]a, input [3:0]b, output [7:0]m);
and(m[0], a[0], b[0]);
wire [14:0]w;
and(w[0], a[1], b[0]);
and(w[1], a[2], b[0]);
and(w[2], a[3], b[0]);
and(w[3], a[0], b[1]);
and(w[4], a[1], b[1]);
and(w[5], a[2], b[1]);
and(w[6], a[3], b[1]);
and(w[7], a[0], b[2]);
and(w[8], a[1], b[2]);
and(w[9], a[2], b[2]);
and(w[10], a[3], b[2]);
and(w[11], a[0], b[3]);
and(w[12], a[1], b[3]);
and(w[13], a[2], b[3]);
and(w[14], a[3], b[3]);
wire [10:0]c;
wire [5:0]s;
full_adder fa1(.a(w[0]), .b(w[3]), .c(0), .sum(m[1]), .carry(c[0]));
full_adder fa2(.a(w[1]), .b(w[4]), .c(c[0]), .sum(s[0]), .carry(c[1]));
full_adder fa3(.a(w[2]), .b(w[5]), .c(c[1]), .sum(s[1]), .carry(c[2]));
full_adder fa4(.a(0), .b(w[6]), .c(c[2]), .sum(s[2]), .carry(c[3]));

full_adder fa5(.a(s[0]), .b(w[7]), .c(0), .sum(m[2]), .carry(c[4]));
full_adder fa6(.a(s[1]), .b(w[8]), .c(c[4]), .sum(s[3]), .carry(c[5]));
full_adder fa7(.a(s[2]), .b(w[9]), .c(c[5]), .sum(s[4]), .carry(c[6]));
full_adder fa8(.a(c[3]), .b(w[10]), .c(c[6]), .sum(s[5]), .carry(c[7]));

full_adder fa9(.a(s[3]), .b(w[11]), .c(0), .sum(m[3]), .carry(c[8]));
full_adder fa10(.a(s[4]), .b(w[12]), .c(c[8]), .sum(m[4]), .carry(c[9]));
full_adder fa11(.a(s[5]), .b(w[13]), .c(c[9]), .sum(m[5]), .carry(c[10]));
full_adder fa12(.a(c[7]), .b(w[14]), .c(c[10]), .sum(m[6]), .carry(m[7]));

endmodule