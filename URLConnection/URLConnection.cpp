#include<Poco/Net/HTTPClientSession.h>
#include<Poco/Net/HTTPRequest.h>
#include<Poco/Net/HTTPResponse.h>
#include<Poco/URI.h>
#include<Poco/Path.h>
#include<Poco/Exception.h>
#include<Poco/StreamCopier.h>
#include<string>
#include <fstream>
#include <iostream>

using namespace std;
using namespace Poco;
using namespace Poco::Net;

class URLConnection {
public:

    URLConnection() {
    }

    string OpenConnection(string url) {
        URI uri(url);
        HTTPClientSession session(uri.getHost(), uri.getPort());
        try {
            string path(uri.getPathAndQuery());
            if (path.empty()) path = "/";

            HTTPRequest req(HTTPRequest::HTTP_GET, path, HTTPMessage::HTTP_1_1);
            session.sendRequest(req);

            HTTPResponse res;
            cout << res.getStatus() << " " << res.getReason() << endl;

            istream &is = session.receiveResponse(res);
            string html;
            StreamCopier::copyToString(is, html, 8192);

            ofstream myfile;
            myfile.open("dataa.txt");
            myfile << html;
            myfile.close();
            
            return html;
            
        } catch (Exception &ex) {
            cerr << ex.displayText() << endl;
        }

    }

    ~URLConnection() {
    }
};
