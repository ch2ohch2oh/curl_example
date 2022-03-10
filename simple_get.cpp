#include <curl/curl.h>

#include <iostream>

uint write_cb(char *data, uint size, uint nmemb, void *userdata)
{
    uint realsize = size * nmemb;
    for (uint i = 0; i < realsize; i++)
    {
        std::cout << data[i];
    }
    return realsize;
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        CURL *curl = nullptr;
        char curl_errbuf[CURL_ERROR_SIZE];
        int err;

        curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
        curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, curl_errbuf);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_cb);
        err = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    else
    {
        std::cout << "usage: " << argv[0] << " [url]" << std::endl;
    }
    return 0;
}