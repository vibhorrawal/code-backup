`timescale 1ns / 1ps
`include "test.v"
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/26/2019 03:38:23 PM
// Design Name: 
// Module Name: test_test
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


module test_test;

reg r1,r2,r3,r4,rr0,rr1;
wire out;
test test_inst(
    out, r1, r2, r3, r4, rr0, rr1);
    
    initial
    begin
    #10
    r1 = 1'b0;
    r2 = 1'b1;
    r3 = 1'b0;
    r4 = 1'b1;
    rr0 = 1'b0;
    rr1 = 1'b0;
    
    #10
    rr1 = 1'b1;
    
    #10
    rr0 = 1'b1;
    rr1 = 1'b0;
    
    #10
    rr1 = 1'b1;
    $dumpfile("power_test.vcd");
    $dumpvars();
    end      
endmodule
