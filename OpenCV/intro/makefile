CC=g++
CFLAGS=-I/usr/local/include/opencv4 
LDFLAGS=-lstdc++ -lopencv_imgcodecs -lopencv_highgui -lopencv_core -lopencv_imgproc -lopencv_videoio -lopencv_video

showim: showim.cpp 
	$(CC) $(CFLAGS) $? -o $@ $(LDFLAGS)

showvid: showvid.cpp
	$(CC) $(CFLAGS) $? -o $@ $(LDFLAGS)

vidtrackbar: vidwithtrackbar.cpp 
	$(CC) $(CFLAGS) $? -o $@ $(LDFLAGS)

transforms: transforms.cpp 
	$(CC) $(CFLAGS) $? -o $@ $(LDFLAGS)

test: test.cpp 
	$(CC) $(CFLAGS) $? -o $@ $(LDFLAGS)

mycanny: mycanny.cpp utils.hpp utils.cpp
	$(CC) $(CFLAGS) mycanny.cpp utils.cpp -o $@ $(LDFLAGS)

laplacian: laplacian.cpp 
	$(CC) $(CFLAGS) $? -o $@ $(LDFLAGS)

houghlines: houghlines.cpp 
	$(CC) $(CFLAGS) $? -o $@ $(LDFLAGS)

clean:
	rm -f showvid showim vidtrackbar transforms test mycanny