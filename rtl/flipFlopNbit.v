//Copyright (C) 2018, Alexander Knapik
//Licensed under the GNU GPL v3.0 or any later version

module flipFlopNbit #(
		      parameter busWidth = 8 //Flip flop bus width. Default = 8 bits.
		    )
     (
      input [(busWidth - 1):0] D,
      input 			clk,
      input 			reset_n,
      output [(busWidth - 1):0] Q      
      );
   

  //Register for holding the output value. Used for assigning in an always block.
  reg [(busWidth - 1):0] q;
   assign Q = q;
   
  
  always @(posedge(clk), negedge(reset_n)) begin
     //If the reset line is low, set the output to be zero despite the input.
     if(reset_n == 1'b0) begin
	q = 0;
     end
     //Else if the reset line is low, and the flip flops are clocked, set the output
     //to equal the input.
     else if (clk == 1'b1) begin
	q = D;
     end
     //Else, keep the output the same.
     else begin
	q = q;
     end
  end//always
   
  endmodule // flipFlopNbit
