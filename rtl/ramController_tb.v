module ramController_tb;

   //Initial, default values.
   reg [8:0] 	Ain;
   reg	     	OEin_n;
   reg 	     	CASU_n;
   reg 		CASL_n;
   reg 		WE_n;
   reg 	   		RAS_n;
   wire [17:0] 		Aout;
   wire 		OEout_n;
   wire 		UB_n;
   wire        	LB_n;
   wire        	CE_n;
   
   initial begin
      //VCD dump file name
      $dumpfile("ramController.vcd");
      //Set up the GTKWave axis titles
      $dumpvars(0, s);
      //Output text setup
      // Use this as a print statement. Not being used as I will be using GTKWave instead.
      // $monitor("");
      
      //Setting each element at each time interval.
      //This must finish with $finish

      //FAST PAGE MODE READ CYCLE
      //-----------------------------------------------------------------------------------
      //FIRST CYCLE: READ FROM BOTH BYTES AT ADDRESS 0x134AF
      //SECOND CYCLE: READ FROM UPPER BYTE AT ADDRESS 0x144AF
      //THIRD CYCLE: RESD FROM LOWER BYTE AT ADDRESS 0x154AF

      //FIRST CYCLE:
      //Initial values. Set all addresses to zero, and all active low inputs high.
      #20 Ain = 8'd0;
      OEin_n = 1'b1;
      CASU_n = 1'b1;
      CASL_n = 1'b1;
      WE_n = 1'b1;
      RAS_n = 1'b1;
      //Set up an input address for reading a specific row index.
      #20 Ain = 9'h0af;
      //set RAS_n low.
      #10 RAS_n = 1'b0;
      //Set WE_n high, as its reading
      #10 WE_n = 1'b1;
      //Set which column index will be read from.
      #10 Ain = 9'h09a;
      //Set both CAS_n lines low. Reading 16 bits of data.
      #10 CASU_n = 1'b0;
      CASL_n = 1'b0;
      //Set the output enable low, as Dout will be active due to a read action.
      #10 OEin_n = 1'b0;
      #10 OEin_n = 1'b1;

      //SECOND CYCLE:
      //Set the CAS_n lines high to indicate that a new column address will be needed.
      //The 68000 will set the data input to high impendance. 
      #20 CASU_n = 1'b1;
      CASL_n = 1'b1;
      //Set WE_n low as once the column address is input, WE_n will be used as a rising edge.
      #10 WE_n = 1'b0;
      //Input the new 9 bit column address. 
      #10 Ain = 9'h09b;
      //Set WE_n to high as the DRAM would require a rising edge of WE_n.
      #10 WE_n = 1'b1;
      //Set CASU_n low to read from the upper byte of 0x144af
      #10 CASU_n = 1'b0;
      //Set the output enable low, allowing Dout to be active for a read cycle.
      #10 OEin_n = 1'b0;
      #10 OEin_n = 1'b1;
      
      //THIRD CYCLE:
      //Set the CAS_n lines high to indicate that a new column address will be needed.
      //The 68000 will set the data input to high impendance. 
      #20 CASU_n = 1'b1;
      CASL_n = 1'b1;
      //Set WE_n low as once the column address is input, WE_n will be used as a rising edge.
      #10 WE_n = 1'b0;
      //Input the new 9 bit column address. 
      #10 Ain = 9'h09c;
      //Set WE_n to high as the DRAM would require a rising edge of WE_n.
      #10 WE_n = 1'b1;
      //Set CASU_n low to read from the upper byte of 0x144af
      #10 CASU_n = 1'b0;
      //Set the output enable low, allowing Dout to be active for a read cycle.
      #10 OEin_n = 1'b0;

      //Set the RAM into standby.
      //Set the RAS_n line high.
      #10 RAS_n = 1'b1;
      //Set the output enable high.
      #10 OEin_n = 1'b1;
      //Set the CAS_n lines high. 
      #10 CASU_n = 1'b1;
      CASL_n = 1'b1;
      //Falling edge of write enable
      #10 WE_n = 1'b0;

      #50 $finish;
   end // initial

   ramController s(Ain, OEin_n, CASU_n, CASL_n, WE_n, RAS_n, Aout, OEout_n, UB_n, LB_n, CE_n);

endmodule // flipFlopNbit_tb
   
