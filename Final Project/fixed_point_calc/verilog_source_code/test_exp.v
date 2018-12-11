module tb(); 

    reg [31:0] x;
    wire [31:0] y;
    reg clk;
    wire done;
    reg start;
    integer count;
    exp uut(
        .x(x),
        .y(y),
        .start(start),
        .done(done),
        .clk(clk)
    );
    always begin
        #1 clk  = ~clk;
    end

    initial begin
        clk <= 0;
        count <= 0;
        //x <= 32'h80048000;
        x <= 32'h00010f00;
        start <= 0;
    end
    

    always@(posedge clk) begin
        $display("x: %h, y: %h, start: %b, done: %b,", x, y, start, done);
        count <= count + 1;
        if (count > 5) begin
            if (count == 550) begin
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
            x = x - 32'ha000;
    end
endmodule