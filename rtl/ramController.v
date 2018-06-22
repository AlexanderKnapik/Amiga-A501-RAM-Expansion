module ramController (
		      input [8:0]   Ain,
		      input 	    OE_n,
		      input [1:0]   CAS_n,
		      input 	    WE_n,
		      input [1:0]   RAS_n,
		      output [17:0] Aout
		      )

  //Instantiate two 9 bit flip flop arrays being used to latch the row and column addresses
  parameter busWidth = 9;

  //Wires used for connecting the Q values of the row and column latches to the IO pins
  //of the FPGA.
  
   wire [(busWidth - 1):0] rowAddress;
   wire [(busWidth - 1):0] columnAddress;
    
  .flipFlopNbit (
		 busWidth
		 )
    rowLatch (
	     .D (addressIn),
	     .CLK (~RAS_n),
	     .reset_n (1'b1),
	     .Q (rowAddress)
	      )

  .flipFlopNbit (
		 busWidth
		 )
    columnLatch (
		 .D (addressIn),
		 .CLK (~CAS_n),
		 .reset_n (1'b1),
		 .Q (columnAddress)
		 )

    
  
  
  endmodule // ramController
