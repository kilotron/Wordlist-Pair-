#include "pch.h"
#include "Preprocess.h"

using namespace std;

set<string> Preprocess::readfile(char *filename) {
	FILE *fp = fopen(filename, "r");
	set<string> retans;
	string ans;
	if (fp != NULL) {
		char c;
		//ÿ�ζ�����Ӧ���ļ�
		while (((c = fgetc(fp)) != EOF)) {
			//��д��ĸת��ΪСд��ĸ
			if (c >= 65 && c <= 90) {
				c += 32;
			}
			//����ĸ������Ӧ���ַ���֮��
			if (c >= 97 && c <= 122) {
				ans.push_back(c);
			}
			else {
				if (ans.length() != 0) {
					string copy(ans);
					retans.insert(copy);
					ans.clear();
				}
			}
		}
		if (ans.length() != 0) {
			retans.insert(ans);
		}
		fclose(fp);
	}
	else {
		throw exception("�ļ����Ƿ������ļ�������");
	}
	return retans;
}

void Preprocess::command(int argc, char *argv[]) {
	if (argc - 1 <= 0) {
		//throw "����ʹ����ָ����Ӧ����";
	}
	int i = 1;
	bool wflag = false, rflag = false, cflag = false;
	while (i < argc - 1)
	{

		if (strcmp(argv[i], "-h") == 0) {
			char *alpha = argv[++i];
			if (strlen(alpha) != 1 || !isalpha(*alpha)) {
				throw exception("-h�����Ӧ�ýӵ����ַ�");
			}
			else {
				*alpha = tolower(*alpha);
				head = alpha[0];
			}
		}
		else if (strcmp(argv[i], "-t") == 0) {
			char *alpha = argv[++i];
			if (strlen(alpha) != 1 || !isalpha(*alpha)) {
				throw exception("-t�����Ӧ�ýӵ����ַ�");
			}
			else {
				*alpha = tolower(*alpha);
				tail = alpha[0];
			}
		}
		else if (strcmp(argv[i], "-w") == 0) {
			wflag = true;
		}
		else if (strcmp(argv[i], "-r") == 0) {
			rflag = true;
		}
		else if (strcmp(argv[i], "-c") == 0) {
			cflag = true;
		}
		else {
			throw exception("����������");
		}
		i++;
	}
	if (cflag && rflag) {
		kind = RC;
	}
	else if (wflag && rflag) {
		kind = RW;
	}
	else if (wflag) {
		kind = W;
	}
	else if (cflag) {
		kind = C;
	}
	else {
		throw exception("���������ʹ�÷�ʽ");
	}

	strcpy(filename, argv[argc - 1]);
}

char ** Preprocess::change(set<string> strSet, int *length) {
	int count = strSet.size();
	*length = count;
	char ** result = (char **)malloc(sizeof(char *)*count);
	int index = 0;
	for (set<string>::iterator iter = strSet.begin(); iter != strSet.end(); iter++) {
		int lengthOfstr = (*iter).size();
		result[index] = (char *)(malloc(sizeof(char) * lengthOfstr + 1));
		strcpy(result[index++], (*iter).c_str());
	}
	return result;
}

void Preprocess::write(char *result[], int length) {
	FILE *wfp;
	wfp = fopen("solution.txt", "w");
	for (int i = 0; i < length; i++) {
		fprintf(wfp, "%s\n", result[i]);
	}
	fclose(wfp);
}