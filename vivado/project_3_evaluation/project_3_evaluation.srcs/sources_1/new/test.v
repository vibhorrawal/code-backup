`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/27/2019 05:56:53 AM
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

`include "rca.v"
module test;
reg [3:0] x,y;
wire [4:0] sum;
rca rca_inst( .out(sum), .a(x), .b(y));

initial 
begin
x = 4'b0000;
y = 4'b0000;
#10;

x = 4'b0001;
y = 4'b0000;
#10;

x = 4'b0001;
y = 4'b0001;
#10;

x = 4'b1111;
x = 4'b1111;
#10;
end 
endmodule
