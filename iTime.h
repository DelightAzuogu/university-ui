#include <mysql.h>
#include <string>
#include <cstring>
#include <iostream>
#include <ctime>

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace std;


	/// <summary>
	/// Summary for iTime
	/// </summary>
	public ref class iTime : public System::Windows::Forms::Form
	{
	public:
		iTime(string idPara, int yearPara, string semesterPara, char* groupPara[], char* courseCodePara[])
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			//connection
			MYSQL* con = mysql_init(NULL);
			con = mysql_real_connect(con, "localhost", "root", "password", "logo_university", 3306, NULL, 0);


			if (con) {
				for (int i = 0; groupPara[i] != '\0' && i < 6; i++) {

					string group(groupPara[i]);
					string courseCode(courseCodePara[i]);

					string query = "select t.course_code, day, start_time, end_time, building, room_number from teaches as t, section as s, time_slot as ts where "
						"s.time_slot_id = ts.time_slot_id and s.course_code = t.course_code and t.group_number = s.group_number "
						" and s.year = t.year and s.semester = t.semester and s.course_code = \"" + courseCode + "\" and s.group_number = " + group +
						" and s.year = " + to_string(yearPara) + " and s.semester = \"" + semesterPara + "\";";


					int check = mysql_query(con, query.c_str());
					if (!check) {
						MYSQL_RES* res = mysql_store_result(con);
						MYSQL_ROW row = mysql_fetch_row(res);
						char fullTimeTable[100] = "";
						strcat(fullTimeTable, row[0]);
						strcat(fullTimeTable, "---");
						strcat(fullTimeTable, row[1]);
						strcat(fullTimeTable, "---");
						strcat(fullTimeTable, row[2]);
						strcat(fullTimeTable, "---");
						strcat(fullTimeTable, row[3]);
						strcat(fullTimeTable, "---");
						strcat(fullTimeTable, row[4]);
						strcat(fullTimeTable, row[5]);

						if (i == 0)
							this->course1time->Text = gcnew String(fullTimeTable);
						else if (i == 1)
							this->course2time->Text = gcnew String(fullTimeTable);
						else if (i == 2)
							this->course3time->Text = gcnew String(fullTimeTable);
						else if (i == 3)
							this->course4time->Text = gcnew String(fullTimeTable);
						else if (i == 4)
							this->course5time->Text = gcnew String(fullTimeTable);
						else if (i == 5)
							this->course6time->Text = gcnew String(fullTimeTable);

						mysql_free_result(res);
					}
				}
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~iTime()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ course6time;
	protected:
	private: System::Windows::Forms::Label^ course5time;
	private: System::Windows::Forms::Label^ course4time;
	private: System::Windows::Forms::Label^ course3time;
	private: System::Windows::Forms::Label^ course2time;
	private: System::Windows::Forms::Label^ course1time;

	protected:






	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->course6time = (gcnew System::Windows::Forms::Label());
			this->course5time = (gcnew System::Windows::Forms::Label());
			this->course4time = (gcnew System::Windows::Forms::Label());
			this->course3time = (gcnew System::Windows::Forms::Label());
			this->course2time = (gcnew System::Windows::Forms::Label());
			this->course1time = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// course6time
			// 
			this->course6time->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->course6time->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->course6time->Location = System::Drawing::Point(12, 279);
			this->course6time->Name = L"course6time";
			this->course6time->Size = System::Drawing::Size(453, 19);
			this->course6time->TabIndex = 11;
			this->course6time->Text = L"         ";
			// 
			// course5time
			// 
			this->course5time->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->course5time->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->course5time->Location = System::Drawing::Point(12, 228);
			this->course5time->Name = L"course5time";
			this->course5time->Size = System::Drawing::Size(453, 19);
			this->course5time->TabIndex = 10;
			this->course5time->Text = L"         ";
			// 
			// course4time
			// 
			this->course4time->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->course4time->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->course4time->Location = System::Drawing::Point(12, 174);
			this->course4time->Name = L"course4time";
			this->course4time->Size = System::Drawing::Size(441, 19);
			this->course4time->TabIndex = 9;
			this->course4time->Text = L"      ";
			// 
			// course3time
			// 
			this->course3time->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->course3time->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->course3time->Location = System::Drawing::Point(12, 121);
			this->course3time->Name = L"course3time";
			this->course3time->Size = System::Drawing::Size(441, 19);
			this->course3time->TabIndex = 8;
			this->course3time->Text = L"      ";
			// 
			// course2time
			// 
			this->course2time->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->course2time->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->course2time->Location = System::Drawing::Point(12, 70);
			this->course2time->Name = L"course2time";
			this->course2time->Size = System::Drawing::Size(441, 19);
			this->course2time->TabIndex = 7;
			this->course2time->Text = L"      ";
			// 
			// course1time
			// 
			this->course1time->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->course1time->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->course1time->Location = System::Drawing::Point(12, 24);
			this->course1time->Name = L"course1time";
			this->course1time->Size = System::Drawing::Size(449, 19);
			this->course1time->TabIndex = 6;
			this->course1time->Text = L"        ";
			// 
			// iTime
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(477, 317);
			this->Controls->Add(this->course6time);
			this->Controls->Add(this->course5time);
			this->Controls->Add(this->course4time);
			this->Controls->Add(this->course3time);
			this->Controls->Add(this->course2time);
			this->Controls->Add(this->course1time);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"iTime";
			this->Text = L"Timetable";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
