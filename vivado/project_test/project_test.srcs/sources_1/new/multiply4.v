`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/26/2019 05:17:16 PM
// Design Name: 
// Module Name: multiply4
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


module multiply4(
output [7:0] p,
input [3:0] a,b
    );
    wire [11:1]c;
    wire [8:1]d, f;
    wire [3:1]e;
    wire [4:1]g;
    
    and(c[1], a[3], b[1]);
    and(c[2], a[2], b[2]);
    and(c[3], a[1], b[3]);
    and(c[4], a[3], b[0]);
    and(c[5], a[2], b[1]);
    and(c[6], a[1], b[2]);
    and(c[7], a[2], b[0]);
    and(c[8], a[1], b[1]);
    and(c[9], a[0], b[2]);
    and(c[10], a[1], b[0]);
    and(c[11], a[0], b[1]);
    and(p[0], a[0], b[0]);
    
    full_adder fa1(d[2],d[1],c[1],c[2],c[3]);
    full_adder fa2(d[4],d[3],c[4],c[5],c[6]);
    full_adder fa3(d[6],d[5],c[7],c[8],c[9]);
    full_adder fa4(p[1],d[7],c[10],c[11],0);
    
    and(e[1],a[2],b[3]);
    and(e[2],a[3],b[2]);
    and(e[3],a[0],b[3]);
    
    full_adder fa5(f[2],f[1],e[1],e[2],d[1]);
    full_adder fa6(f[4],f[3],d[2],d[3],f[5]);
    full_adder fa7(f[6],f[5],d[4],e[3],d[5]);
    full_adder fa8(p[2],f[7],d[6],d[7],0);
    
    

endmodule
