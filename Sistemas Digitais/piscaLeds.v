module piscaleds(
	input CLOCK_50,
	input [3:0] KEY,
	input [9:0] SW,
	output [7:0] LEDG,
	output [9:0] LEDR
	
);
reg [9:0] clk = 0;
reg [27:0] contador = 0;
assign LEDR = clk;
assign LEDG = clk;


always @(posedge CLOCK_50) begin 
	contador = contador + 1;
	if(SW[0] == 1)begin
		if (contador == 25000000)begin//0.5 segundo
				contador = 0;
				clk = ~clk;
			end
	end
	if(SW[1] == 1) begin
		if (contador == 50000000)begin//1 segundo
			contador = 0;
		   clk = ~clk;
		end
	end
	if(SW[2] == 1)begin
		if (contador == 100000000)begin//2 segundos
			contador = 0;
		   clk = ~clk;
		end
	end
	if(SW[3] == 1)begin
		if (contador == 150000000)begin//3 segundos
			contador = 0;
		   clk = ~clk;
		end
	end
	if(SW[4] == 1)begin
		if (contador == 200000000)begin//4 segundos
			contador = 0;
		   clk = ~clk;
		end
	end
	end
endmodule