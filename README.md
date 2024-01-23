# Benchmark

The benchmark consists of two applications (frame.cpp & inplace.cpp) which runs the respective exanic functions (`exanic_receive_frame` and `exanic_receive_chunk_inplace_ex`) till 10M frames have been read. Both applications are launched at the same time (`./frame & ./inplace.cpp &`) to ensure that they receive the same frame. After receiving a frame, some state (exanic frame receive timestamp, application frame receive timestamp, stream id, sequence no, and current function call count) is stored in a vector which is later dumped into a csv file. The jupyter notebook processes the csv to generate the following results for each stream:

## Function Calls till Nth Frame

This graph shows the number of function calls made by each application after a particular frame has been read by both applications. Higher function call count indicates that the function polls more frequently when waiting for a valid frame i.e. each individual function call is faster.

## System Clock Difference on frame receive (exanic_receive_frame - exanic_receive_chunk_inplace_ex)

This is the difference between the system time reported by each application immediately after a valid frame has been received. A positive difference indicates that `exanic_receive_frame` took more time to finish executing when a valid frame is received.

## Conclusion

The results for each stream can be see at https://github.com/avijeet-zanskar/exanic-frame-vs-inplace/blob/master/analyze.ipynb. `exanic_receive_chunk_inplace_ex` is consistently faster across all streams for both metrics.
