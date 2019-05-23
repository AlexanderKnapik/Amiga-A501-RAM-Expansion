module flipFlopNbit_tb;

   //Initial, default values.
   reg [7:0] D = 7'd0;
   reg 	     clk = 1'b0;
   reg 	     reset_n = 1'b0;
   wire [7:0] Q;

   initial
     begin
	//VCD dump file name
	$dumpfile("flipFlopNbit.vcd");
	//Set up the GTKWave axis titles
	$dumpvars(0, s);
	//Output text setup
	$monitor("D is %b, clk is %b, reset_n is %b, D is %b.", D, clk, reset_n, Q);


	//Setting each element at each time interval.
	//This must finish with $finish
   //Keep reset low for 20 periods.
   # 20 reset_n = 1;
   //Increment D every 50 periods
   # 50 D = 8'd1;
   # 50 D = 8'd2;
   # 50 D = 8'd3;
   # 50 D = 8'd4;
   # 50 D = 8'd5;
   # 50 D = 8'd6;
   # 50 D = 8'd7;
   # 50 D = 8'd10;
   # 50 D = 8'd20;
   # 50 D = 8'd200;
   # 50 reset_n = 0;
   # 200 $finish;
	
 	end // initial begin

   	//Make a clock signal for clk.
	always #5 clk = !clk;

   	flipFlopNbit s (D, clk, reset_n, Q);

endmodule // flipFlopNbit_tb

   

   
