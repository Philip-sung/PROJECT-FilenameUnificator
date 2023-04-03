#include <filesystem>
#include <direct.h> 
#include <iostream>
#include <string>
#include <time.h>

using namespace std::filesystem;

std::string MonthToNum(std::string sm);

template <typename TP>
std::time_t to_time_t(TP tp);

int main(void)
{

	std::error_code fError;
	path curpath = current_path();
	directory_entry curFile;
	std::string curFileName;
	std::string curFileNameModif;
	const std::string blank = "";
	int trigger = 0;

	std::cout << "Objective Directory : " << curpath << std::endl;

	directory_iterator iter = directory_iterator(curpath);

	std::cout << "Starting Point : " << *iter << std::endl;
	std::cout << "Do you want to Add Time information to the files? (Enter 1 for YES and 0 for NO)\n";
	std::cin >> trigger;
	while (trigger != 0 && trigger != 1) {
		std::cout << "Wrong Input\n";
		std::cout << "Do you want to Add Time information to the files? (Enter 1 for YES and 0 for NO)\n";
		std::cin >> trigger;
	}

	while (iter != end(iter)) {
		//Find All Files and list the names
		curFile = *iter;
		path curFilePath = curFile.path();
		curFileName = curFile.path().filename().string();
		curFileNameModif = curFileName;

		//find strings and replace them with blank
		std::string find_str = "Screenshot_";
		if(curFileName.find(find_str) != std::string::npos){
			curFileName.replace(curFileName.find(find_str), find_str.length(), blank);
			if (curFileName[0] == '2' && curFileName[1] == '0' && curFileName[7] != '_') {
				int fSize = curFileName.size();
				for (int i = 0; i < fSize; i++) {
					if (curFileName[i] == '-') {
						curFileName.erase(i, 1);
						fSize = fSize - 1;
					}
					if (curFileName[i] == '_') {
						curFileName.erase(i, 1);
						fSize = fSize - 1;
					}
				}
				curFileName.insert(8, "_");
			}

			path newpath = curpath.string() + "\\" + curFileName;
			rename(curFile.path(), newpath);
			std::cout << "Origianl Path : " << curFile.path() << "**" << std::endl;
			std::cout << "Modified Path : " << newpath << "**" << std::endl;
			curFileNameModif = curFileName;
		}

		//find strings and replace them with blank
		find_str = "kakaotalk_";
		if (curFileName.find(find_str) != std::string::npos) {
			curFileName.replace(curFileName.find(find_str), find_str.length(), blank);
			if (curFileName[0] == '2' && curFileName[1] == '0' && curFileName[7] != '_') {
				int fSize = curFileName.size();
				for (int i = 0; i < fSize; i++) {
					if (curFileName[i] == '-') {
						curFileName.erase(i, 1);
						fSize = fSize - 1;
					}
					if (curFileName[i] == '_') {
						curFileName.erase(i, 1);
						fSize = fSize - 1;
					}
				}
				curFileName.insert(8, "_");
			}

			path newpath = curpath.string() + "\\" + curFileName;
			rename(curFile.path(), newpath);
			std::cout << "Origianl Path : " << curFile.path() << "**" << std::endl;
			std::cout << "Modified Path : " << newpath << "**" << std::endl;
			curFileNameModif = curFileName;
		}
		
		//find strings and replace them with blank
		find_str = "KakaoTalk_";
		if (curFileName.find(find_str) != std::string::npos) {
			curFileName.replace(curFileName.find(find_str), find_str.length(), blank);
			if (curFileName[0] == '2' && curFileName[1] == '0' && curFileName[7] != '_') {
				int fSize = curFileName.size();
				for (int i = 0; i < fSize; i++) {
					if (curFileName[i] == '-') {
						curFileName.erase(i, 1);
						fSize = fSize - 1;
					}
					if (curFileName[i] == '_') {
						curFileName.erase(i, 1);
						fSize = fSize - 1;
					}
				}
				curFileName.insert(8, "_");
			}

			path newpath = curpath.string() + "\\" + curFileName;
			rename(curFile.path(), newpath);

			std::cout << "Origianl Path : " << curFile.path() << "**" << std::endl;
			std::cout << "Modified Path : " << newpath << "**" << std::endl;
			curFileNameModif = curFileName;
		}

		//Extract 8digit YYYYMMDD
		auto timeinf = curFile.last_write_time();
		std::time_t tt = to_time_t(timeinf);
		char timeval[256];
		ctime_s(timeval, sizeof(timeval), &tt);
		std::string timestr = timeval;
		std::cout << curFileName << " - " << timestr;
		std::string year;
		year.push_back(timestr[20]); year.push_back(timestr[21]); year.push_back(timestr[22]); year.push_back(timestr[23]);

		std::string month;
		month.push_back(timestr[4]); month.push_back(timestr[5]); month.push_back(timestr[6]);
		month = MonthToNum(month);

		std::string day;
		if (timestr[8] == '1' || timestr[8] == '2' || timestr[8] == '3')
			day.push_back(timestr[8]);
		else
			day.push_back('0');
		day.push_back(timestr[9]);
		std::cout << year + month + day << std::endl;
		//Extracting YYYYMMDD ENDS


		path curpathmod = curpath.string() + "\\" + curFileNameModif;
		if (curFileName[0] == '2' && curFileName[1] == '0' && curFileName[8] != '_') {
			int fSize = curFileName.size();
			for (int i = 0; i < fSize; i++) {
				if (curFileName[i] == '-') {
					curFileName.erase(i, 1);
					fSize = fSize - 1;
				}
				if (curFileName[i] == '_') {
					curFileName.erase(i, 1);
					fSize = fSize - 1;
				}
			}
			curFileName.insert(8, "_");
			path newpath = curpath.string() + "\\" + curFileName;
			rename(curpathmod, newpath);
			std::cout << "Origianl Path : " << curpathmod << "**" << std::endl;
			std::cout << "Modified Path : " << newpath << "**" << std::endl;
		}
		else if (curFileName[0] == '2' && curFileName[1] == '0' && curFileName[8] == '_') {
			int fSize = curFileName.size();
			for (int i = 0; i < fSize; i++) {
				if (curFileName[i] == '-') {
					curFileName.erase(i, 1);
					fSize = fSize - 1;
				}
				if (curFileName[i] == '_') {
					curFileName.erase(i, 1);
					fSize = fSize - 1;
				}
			}
		}
		else if (trigger == 1) {
			int fSize = curFileName.size();
			for (int i = 0; i < fSize; i++) {
				if (curFileName[i] == '-') {
					curFileName.erase(i, 1);
					fSize = fSize - 1;
				}
				if (curFileName[i] == '_') {
					curFileName.erase(i, 1);
					fSize = fSize - 1;
				}
			}
			curFileName.insert(0, year + month + day + "_");
			path newpath = curpath.string() + "\\" + curFileName;
			std::cout << curFile.path() << std::endl;
			std::cout << newpath << std::endl;
			rename(curpathmod, newpath);
			std::cout << "Origianl Path : " << curpathmod << "**" << std::endl;
			std::cout << "Modified Path : " << newpath << "**" << std::endl;
		}

		//Increment
		iter++;
	
	}

	std::cout << "\n** File Name Standardization Executed Successfully **\n";
	std::cin.get();
	std::cin.get();

	return 0;
}

template <typename TP>
std::time_t to_time_t(TP tp)
{
	using namespace std::chrono;
	auto sctp = time_point_cast<system_clock::duration>(tp - TP::clock::now()
		+ system_clock::now());
	return system_clock::to_time_t(sctp);
}

std::string MonthToNum(std::string sm)
{
	std::string nm;
	if (sm == "Jan")
		nm = "01";
	else if (sm == "Feb")
		nm = "02";
	else if (sm == "Mar")
		nm = "03";
	else if (sm == "Apr")
		nm = "04";
	else if (sm == "May")
		nm = "05";
	else if (sm == "Jun")
		nm = "06";
	else if (sm == "Jul")
		nm = "07";
	else if (sm == "Aug")
		nm = "08";
	else if (sm == "Sep")
		nm = "09";
	else if (sm == "Oct")
		nm = "10";
	else if (sm == "Nov")
		nm = "11";
	else if (sm == "Dec")
		nm = "12";

	return nm;
}