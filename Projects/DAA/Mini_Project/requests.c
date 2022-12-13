#include<stdio.h>
#include <curl/curl.h>
#include<stdlib.h>
#include<string.h>

int main(){
    // CURL * curl = curl_easy_init();
    char min[2] = '10';
    char max[2] = '20';
    char n = '5';
    char * URL1 = "https://www.random.org/integers/\?num\\=";
    char * strcat
    char *URL[3] = {"https://www.random.org/integers/\?num\\=",n,"\\&min\\=",min,"\\&max\\=", max, "\\&col\\=1\\&base\\=10\\&format\\=plain\\&rnd\\=new"};
    // curl_easy_setopt(curl, CURLOPT_URL, URL);

    // curl_easy_cleanup(curl);
    printf("\n%s", URL);
}