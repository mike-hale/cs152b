module tb(); 

    reg [31:0] x;
    wire [31:0] y;
    reg clk;
    wire done;
    wire [31:0] dbg[2:0];
    reg start;
    integer count;
    real calc_out;
    exp uut(
        .x(x),
        .y(y),
        .start(start),
        .done(done),
        .clk(clk),
        .dbg(dbg[0]),
        .dbg2(dbg[1]),
        .dbg3(dbg[2])
    );
    always begin
        #1 clk  = ~clk;
    end

    initial begin
        clk <= 0;
        count <= 0;
        x <= 32'h80048000;
        start <= 0;
    end
    

    always@(posedge clk) begin
        //$display("x: %h, y: %h, start: %b, done: %b, %h, %h, %h", x, y, start, done, dbg[0], dbg[1], dbg[2]);
        count <= count + 1;
        if (count > 5) begin
            if (count == 200) begin
                $finish;
            end else begin
                count <= count + 1;
                if(done == 1) begin
                    start <= 1;
                end else begin
                    start <= 0;  
                end
            end
        end
    end

    always @ (posedge done) begin
        $display("Answer: %h, %h, %d", x, y, count);
        if(count > 6)
            x = x - 32'hc000;
    end
endmodule