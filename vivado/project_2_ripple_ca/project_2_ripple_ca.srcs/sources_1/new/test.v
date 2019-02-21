`include "ripple_adder.v"
 
module test;
 
 
  reg [3:0] r_ADD_1 = 0;
  reg [3:0] r_ADD_2 = 0;
  wire [4:0]  w_RESULT;
   
  ripple_adder adder_inst
    (
     .a(r_ADD_1),
     .b(r_ADD_2),
     .out(w_RESULT)
     );
 
  initial
    begin
      #10;
      r_ADD_1 = 4'b0000;
      r_ADD_2 = 4'b0001;
      #10;
      r_ADD_1 = 4'b0100;
      r_ADD_2 = 4'b0010;
      #10;
      r_ADD_1 = 4'b0001;
      r_ADD_2 = 4'b0001;
      #10;
      r_ADD_1 = 4'b1000;
      r_ADD_2 = 4'b1000;
      #10;
      
      $dumpfile("power_test.vcd");
      $dumpvars();
    end
 
endmodule // carry_lookahead_adder_tb