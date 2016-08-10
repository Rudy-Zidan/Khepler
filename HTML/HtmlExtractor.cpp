#include<string>
#include<vector>

using namespace std;

class HtmlExtractor {
public:

    HtmlExtractor() {
    }

    string NormalizeHtml(string html) {
        if (html != "") {
            string beginStr = "<html>", endStr = "</html>";
            unsigned int beginPos = html.find(beginStr.c_str()), endPos = html.find(endStr.c_str()), invalidPos = html.length();
            if (beginPos != invalidPos && endPos != invalidPos && endPos > beginPos) {
                unsigned int urlLen = endPos - beginPos + endStr.length();
                html = html.substr(beginPos, urlLen);
            }
            return html;
        }
    }

    string TrimStyleTag(string html) {
        if (html != "") {
style:
            string beginStr = "<style", endStr = "</style>";
            unsigned int beginPos = html.find(beginStr.c_str()), endPos = html.find(endStr.c_str()), invalidPos = html.length();
            if (beginPos != invalidPos && endPos != invalidPos && endPos > beginPos) {
                unsigned int urlLen = endPos - beginPos + endStr.length();
                string vhtml = html.substr(beginPos, urlLen);
                html.replace(beginPos, vhtml.length(), "");
                goto style;
            }
            return html;
        }
    }

    string TrimLinkTag(string html) {
        if (html != "") {
link:
            string beginStr = "<link", endStr = "/>";
            unsigned int beginPos = html.find(beginStr.c_str()), endPos = html.find(endStr.c_str()), invalidPos = html.length();
            if (beginPos != invalidPos && endPos != invalidPos && endPos > beginPos) {
                unsigned int urlLen = endPos - beginPos + endStr.length();
                string vhtml = html.substr(beginPos, urlLen);
                html.replace(beginPos, vhtml.length(), "");
                goto link;
            }
            return html;
        }
    }

    string TrimScriptTag(string html) {
        if (html != "") {
script:
            string beginStr = "<script", endStr = "</script>";
            unsigned int beginPos = html.find(beginStr.c_str()), endPos = html.find(endStr.c_str()), invalidPos = html.length();
            if (beginPos != invalidPos && endPos != invalidPos && endPos > beginPos) {
                unsigned int urlLen = endPos - beginPos + endStr.length();
                string vhtml = html.substr(beginPos, urlLen);
                html.replace(beginPos, vhtml.length(), "");
                goto script;
            }
            return html;
        }
    }

    vector<string> GetURI(string html) {
        if (html != "") {
            vector<string>urilist;
            html = NormalizeHtml(html);
            html = TrimLinkTag(html);
            html = TrimScriptTag(html);
            html = TrimStyleTag(html);

            string tmp;
link:
            string beginStr = "<a", endStr = "></a>";
            unsigned int beginPos = html.find(beginStr.c_str()), endPos = html.find(endStr.c_str()), invalidPos = html.length();
            if (beginPos != invalidPos && endPos != invalidPos && endPos > beginPos) {
                unsigned int urlLen = endPos - beginPos + endStr.length();
                tmp = html.substr(beginPos, urlLen);
                string vhtmll = html.substr(beginPos, urlLen);
                html.replace(beginPos, vhtmll.length(), "");


                beginStr = "href=", endStr = ">";
                beginPos = tmp.find(beginStr.c_str()), endPos = tmp.find(endStr.c_str()), invalidPos = tmp.length();
                if (beginPos != invalidPos && endPos != invalidPos && endPos > beginPos) {
                    unsigned int urlLen = endPos - beginPos + endStr.length();
                    tmp = tmp.substr(beginPos, urlLen);
                    tmp = tmp.substr(6, tmp.length() - 2);
                    int last = tmp.find(" ");
                    tmp = tmp.substr(0, last - 1);
                    if (tmp != "") {
                        if (tmp[tmp.size() - 1] == '>' && tmp[tmp.size() - 2] == '\"')
                            tmp = tmp.substr(0, tmp.size() - 2);
                        urilist.push_back(tmp);
                    }
                }
                goto link;
            }
            return urilist;
        }
    }

    string GetText(string html) {
        if (html != "") {
            html = NormalizeHtml(html);
            html = TrimLinkTag(html);
            html = TrimStyleTag(html);
            html = TrimScriptTag(html);

            string text;
            string tmp;
            int nl = 0;
            int flag = 0;
            int begin = 0;
            int final = 0;
            for (long unsigned int i = 0; i < html.length(); i++) {
                if (html.at(i) == '<') {
                    flag = 1;
                } else {
                    if (html.at(i) == '>') {
                        flag = 0;
                        continue;
                    }
                }
                if (flag == 0) {
                    tmp += html.at(i);
                }

            }
            text = tmp;

            return text;
        }
    }

    ~HtmlExtractor() {
    }
};
