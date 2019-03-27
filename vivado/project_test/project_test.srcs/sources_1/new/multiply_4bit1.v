`timescale 1ns / 1ps
`include "full_adder.v"
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/26/2019 05:48:06 PM
// Design Name: 
// Module Name: multiply_4bit
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


module multiply_4bit1(
output [7:0] p,
input [3:0] a, b
    );
    
    wire c2,c3,c4,c5,c6;
    wire w0,w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,w12,w13,w14;
    wire t0,t1,t2,t3,t4,t5;
    wire d0,d1,d2,d3,d4,d5;
    
    //bit 0
    and(p[0], a[0], b[0]);
    
    // bit 1
    and(w0,a[0],b[1]),      (w1,a[1],b[0]);
    full_adder fa1(p[1],c2,w1,w0,0);
    
    //bit 2
    and(w2,a[2],b[0]),      (w3,a[1],b[1]),    (w4,a[0],b[2]);
    full_adder fa2(t0,d0,w2,w3,c2);
    full_adder fa3(p[2],c3,w4,t0,d0);
    
    //bit 3
    and(w5,a[3],b[0]),    (w6,a[2],b[1]),      (w7,a[1],b[2]),       (w8,a[0],b[3]);
    full_adder fa4(t1,d1,w5,w6,c3);
    full_adder fa5(t2,d2,w7,t1,d1);
    full_adder fa6(p[3],c4,w8,t2,d2);
    
    //bit 4
    and(w9,a[3],b[1]),     (w10,a[2],b[2]),    (w11,a[1],b[3]);
   full_adder fa7(t3,d3,w9,0,c4);
   full_adder fa8(t4,d4,w10,t3,d3);
   full_adder fa11(p[4],c5,w11,t4,d4);
        
    //bit5
    and(w12,a[3],b[2]),   (w13,a[2],b[3]);
    full_adder fa12(t5,d5,d4,w12,d3);
    full_adder fa9(p[5],c6,w13,t5,d5);

    //bit 6 and bit 7
    and(w14,a[3],b[3]);
    full_adder fa10(p[6],p[7],w14,c6,0);

endmodule
