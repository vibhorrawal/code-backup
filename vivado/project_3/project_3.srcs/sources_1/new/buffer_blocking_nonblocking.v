`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/27/2019 06:10:19 AM
// Design Name: 
// Module Name: buffer_blocking_nonblocking
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


module buffer_blocking_nonblocking(
    input in,
    output o1,
    output o2,
    output o3,
    output o4,
    output o5,
    output o6
    );
    reg r1,r2,r3,r4,r5,r6;
    wire r = in;
    
    always@(r)
    begin
    r1 = r; // blocking & No delay
    end
    assign o1 = r1;
    
    always@(r)
    begin
    r2 = r; // Non blocking & No delay
    end
    assign o2 = r2;
    
    always@(r)
    begin
    #5 r3 = r; // blocking & delayed evaluation
    end
    assign o3 = r3;

    always@(r)
    begin
    #5 r4 <= r; // Non blocking & delayed evaluation
    end
    assign o4 = r4;

    always@(r)
    begin
    r5 =#5 r; // Non blocking & No delay
    end
    assign o5 = r5;

    always@(r)
    begin
    r6 <= #5 r; // Non blocking & No delay
    end
    assign o6 = r6;
         
endmodule
