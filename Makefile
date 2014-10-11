cjson_sample: cjson_sample.cpp
	g++ -Wall -g -o cjson_sample cjson_sample.cpp -std=c++11 -x c cJSON.c

clean:
	rm -rf cjson_sample
