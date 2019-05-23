//Copyright (C) 2018 Alexander Knapik
//Under the GNU General Public License v3.0 or any later version.

module ramController (
		      input [8:0]   Ain, //Input Address
		      input 	    OEin_n, //Input output Enable
		      input 	    CASU_n, //Input Column Address Strobe for upper byte
		      input 	    CASL_n, //Input Column Address Strobe for lower byte.
		      input 	    WE_n, //Input Write enable.
		      input 	    RAS_n, //Input Row Address Strobe.
		      output [17:0] Aout, //Output Address
		      output 	    OEout_n, //Output SRAM output enable
		      output 	    UB_n,
		      output 	    LB_n,
		      output 	    CE_n //Output SRAM chip enable.
		      );
   
   //Registers for assigning value in an always block.
   reg ce_n;
   assign CE_n = ce_n;
   
   reg lb_n;
   reg ub_n;
   assign LB_n = lb_n;
   assign UB_n = ub_n;

   reg [17:0] addressOut = 18'd0;
   assign Aout = addressOut;
      
   //For the Output Enable signal output, have it follow the input.
   //This is mainly for debugging to ensure that connecting it straight to the
   //RAM doesn't cause an issue further in the line after a PCB is made.
   assign OEout_n = OEin_n;
   
   //Instantiate two 9 bit flip flop arrays being used to latch the row and column addresses
   parameter busWidth = 9;

   //Wires used for connecting the Q values of the row and column latches to the IO pins
   //of the FPGA.
   wire [(busWidth - 1):0] rowAddress;
     
   //The reset lines are set to clear the latches once the various AS_n lines go high.
   //The clk is set to be the inverse of the varioud AS_n lines. 
    
   flipFlopNbit #(
		  busWidth
		  )
   rowLatch (
	     .D (Ain),
	     .clk (~RAS_n),
	     .reset_n (1'b1),
	     .Q (rowAddress)
	     );

   //If the RAS_n line goes low, set CE_n low.
   //This is so that once the RAS_n line goes low, this takes the RAM out of standby mode.
   always @(negedge(RAS_n)) begin
      if(RAS_n == 1'b0) begin
	 ce_n <= 1'b0;
      end
      else begin
	 ce_n <= 1'b1;
      end
   end //Always

   //If the CAS_n line goes low,
   //Set the output address to equal the rowAddress and the columnAddress wires.
   //Enable UB_n & LB_n depending on the CAS lines.
   always @(negedge(CASU_n), negedge(CASL_n)) begin
      if(CASU_n == 1'b0) begin
	 ub_n = 1'b0;
      end
      else begin
	 ub_n = 1'b1;
      end

      if(CASL_n == 1'b0) begin
	 lb_n = 1'b0;
      end
      else begin
	 lb_n = 1'b1;
      end
   end // always @ (negedge(CASU_n), negedge(CASL_n))
   
   always @(negedge(CASU_n), negedge(CASL_n)) begin
      addressOut [8:0] = rowAddress;
      addressOut [17:9] = Ain;
   end
   
   
 endmodule // ramController
