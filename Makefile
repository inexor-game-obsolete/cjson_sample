cjson_sample: cjson_sample.cpp
	g++ -Wall -g -o cjson_sample cjson_sample.cpp -x c cJSON.c

clean:
	rm -rf cjson_sample
