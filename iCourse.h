#pragma once
#pragma once
#include <mysql.h>
#include <string>
#include <cstring>
#include <iostream>
#include <ctime>
#include <cstdlib>


namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace std;
	string isemester;
	string iCourseCodeString;

	/// <summary>
	/// Summary for iCourse
	/// </summary>
	public ref class iCourse : public System::Windows::Forms::Form
	{
		int year;
	public:
		iCourse(char* courseCodePara, int yearPara, string semesterPara)
		{
			isemester = semesterPara;
			year = yearPara;


			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			MYSQL* con = mysql_init(NULL);
			con = mysql_real_connect(con, "localhost", "root", "password", "logo_university", 3306, NULL, 0);
			string courseCodeString(courseCodePara);
			iCourseCodeString = courseCodeString;

			if (con) {
				string query = "select title, credit,textbook, comment from course where course_code = \"" + courseCodeString + "\" ;";
				int check = mysql_query(con, query.c_str());
				if (!check) {
					MYSQL_RES* res = mysql_store_result(con);
					MYSQL_ROW row = mysql_fetch_row(res);
					this->titleLabel->Text = gcnew String(row[0]);
					this->creditLabel->Text = gcnew String(row[1]);
					this->textbookLabel->Text = gcnew String(row[2]);
					this->textbookBox->Text = gcnew String(row[2]);
					this->commentBox->Text = gcnew String(row[3]);
				}

				query = "select first_name, last_name from takes, student where id = s_id and course_code = \"" + courseCodeString + "\" and year = " + to_string(year) +
					" and semester = \"" + semesterPara + "\";";
				check = mysql_query(con, query.c_str());
				if (!check) {
					MYSQL_RES* res = mysql_store_result(con);
					MYSQL_ROW row;
					while ((row = mysql_fetch_row(res)) != NULL) {
						string fName(row[0]);
						string lName(row[1]);
						string name = fName + " " + lName;
						String^ s = gcnew String(name.c_str());
						this->studentList->Items->Add(s);
					}
				}
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~iCourse()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ titleLabel;
	protected:

	private: System::Windows::Forms::Label^ creditLabel;
	private: System::Windows::Forms::Label^ textbookLabel;
	private: System::Windows::Forms::Button^ changeTextbook;
	private: System::Windows::Forms::ListBox^ studentList;
	private: System::Windows::Forms::TextBox^ commentBox;
	private: System::Windows::Forms::TextBox^ studentNumber;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ addCommentButton;
	private: System::Windows::Forms::Button^ addstudentButton;

	private: System::Windows::Forms::Label^ addStudentError;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ gradeError;
	private: System::Windows::Forms::Button^ gradeButton;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ gradeStudentNumber;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ grade;
	private: System::Windows::Forms::TextBox^ textbookBox;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::PictureBox^ pictureBox2;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(iCourse::typeid));
			this->titleLabel = (gcnew System::Windows::Forms::Label());
			this->creditLabel = (gcnew System::Windows::Forms::Label());
			this->textbookLabel = (gcnew System::Windows::Forms::Label());
			this->changeTextbook = (gcnew System::Windows::Forms::Button());
			this->studentList = (gcnew System::Windows::Forms::ListBox());
			this->commentBox = (gcnew System::Windows::Forms::TextBox());
			this->studentNumber = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->addCommentButton = (gcnew System::Windows::Forms::Button());
			this->addstudentButton = (gcnew System::Windows::Forms::Button());
			this->addStudentError = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->gradeError = (gcnew System::Windows::Forms::Label());
			this->gradeButton = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->gradeStudentNumber = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->grade = (gcnew System::Windows::Forms::TextBox());
			this->textbookBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// titleLabel
			// 
			this->titleLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->titleLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->titleLabel->Location = System::Drawing::Point(12, 80);
			this->titleLabel->Name = L"titleLabel";
			this->titleLabel->Size = System::Drawing::Size(668, 23);
			this->titleLabel->TabIndex = 0;
			this->titleLabel->Text = L"Title";
			// 
			// creditLabel
			// 
			this->creditLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->creditLabel->AutoSize = true;
			this->creditLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->creditLabel->Location = System::Drawing::Point(12, 103);
			this->creditLabel->Name = L"creditLabel";
			this->creditLabel->Size = System::Drawing::Size(47, 19);
			this->creditLabel->TabIndex = 1;
			this->creditLabel->Text = L"credit";
			// 
			// textbookLabel
			// 
			this->textbookLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textbookLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textbookLabel->Location = System::Drawing::Point(12, 122);
			this->textbookLabel->Name = L"textbookLabel";
			this->textbookLabel->Size = System::Drawing::Size(668, 23);
			this->textbookLabel->TabIndex = 2;
			this->textbookLabel->Text = L"textbook";
			// 
			// changeTextbook
			// 
			this->changeTextbook->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->changeTextbook->Location = System::Drawing::Point(12, 178);
			this->changeTextbook->Name = L"changeTextbook";
			this->changeTextbook->Size = System::Drawing::Size(258, 27);
			this->changeTextbook->TabIndex = 3;
			this->changeTextbook->Text = L"Change Textbook";
			this->changeTextbook->UseVisualStyleBackColor = true;
			this->changeTextbook->Click += gcnew System::EventHandler(this, &iCourse::changeTextbook_Click);
			// 
			// studentList
			// 
			this->studentList->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->studentList->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->studentList->FormattingEnabled = true;
			this->studentList->Location = System::Drawing::Point(16, 212);
			this->studentList->Name = L"studentList";
			this->studentList->Size = System::Drawing::Size(254, 277);
			this->studentList->TabIndex = 4;
			// 
			// commentBox
			// 
			this->commentBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->commentBox->BackColor = System::Drawing::SystemColors::Window;
			this->commentBox->Location = System::Drawing::Point(310, 152);
			this->commentBox->MaxLength = 1000;
			this->commentBox->Multiline = true;
			this->commentBox->Name = L"commentBox";
			this->commentBox->Size = System::Drawing::Size(356, 119);
			this->commentBox->TabIndex = 5;
			// 
			// studentNumber
			// 
			this->studentNumber->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->studentNumber->BackColor = System::Drawing::SystemColors::Window;
			this->studentNumber->Location = System::Drawing::Point(132, 31);
			this->studentNumber->MaxLength = 10;
			this->studentNumber->Name = L"studentNumber";
			this->studentNumber->Size = System::Drawing::Size(203, 20);
			this->studentNumber->TabIndex = 7;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(10, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(116, 19);
			this->label1->TabIndex = 8;
			this->label1->Text = L"student Number";
			// 
			// addCommentButton
			// 
			this->addCommentButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->addCommentButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addCommentButton->Location = System::Drawing::Point(364, 277);
			this->addCommentButton->Name = L"addCommentButton";
			this->addCommentButton->Size = System::Drawing::Size(254, 27);
			this->addCommentButton->TabIndex = 6;
			this->addCommentButton->Text = L"Add comment";
			this->addCommentButton->UseVisualStyleBackColor = true;
			this->addCommentButton->Click += gcnew System::EventHandler(this, &iCourse::addCommentButton_Click);
			// 
			// addstudentButton
			// 
			this->addstudentButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->addstudentButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addstudentButton->Location = System::Drawing::Point(40, 86);
			this->addstudentButton->Name = L"addstudentButton";
			this->addstudentButton->Size = System::Drawing::Size(254, 27);
			this->addstudentButton->TabIndex = 9;
			this->addstudentButton->Text = L"Add Student";
			this->addstudentButton->UseVisualStyleBackColor = true;
			this->addstudentButton->Click += gcnew System::EventHandler(this, &iCourse::studentNumberError_Click);
			// 
			// addStudentError
			// 
			this->addStudentError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->addStudentError->AutoSize = true;
			this->addStudentError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addStudentError->Location = System::Drawing::Point(36, 54);
			this->addStudentError->Name = L"addStudentError";
			this->addStudentError->Size = System::Drawing::Size(49, 19);
			this->addStudentError->TabIndex = 10;
			this->addStudentError->Text = L"          ";
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupBox1->Controls->Add(this->addStudentError);
			this->groupBox1->Controls->Add(this->addstudentButton);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->studentNumber);
			this->groupBox1->Location = System::Drawing::Point(310, 310);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(351, 135);
			this->groupBox1->TabIndex = 11;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Add Student";
			// 
			// gradeError
			// 
			this->gradeError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->gradeError->AutoSize = true;
			this->gradeError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gradeError->Location = System::Drawing::Point(299, 524);
			this->gradeError->Name = L"gradeError";
			this->gradeError->Size = System::Drawing::Size(49, 19);
			this->gradeError->TabIndex = 14;
			this->gradeError->Text = L"          ";
			// 
			// gradeButton
			// 
			this->gradeButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->gradeButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gradeButton->Location = System::Drawing::Point(16, 521);
			this->gradeButton->Name = L"gradeButton";
			this->gradeButton->Size = System::Drawing::Size(254, 27);
			this->gradeButton->TabIndex = 13;
			this->gradeButton->Text = L"Grade";
			this->gradeButton->UseVisualStyleBackColor = true;
			this->gradeButton->Click += gcnew System::EventHandler(this, &iCourse::gradeButton_Click);
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(4, 494);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(116, 19);
			this->label4->TabIndex = 12;
			this->label4->Text = L"student Number";
			// 
			// gradeStudentNumber
			// 
			this->gradeStudentNumber->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->gradeStudentNumber->BackColor = System::Drawing::SystemColors::Window;
			this->gradeStudentNumber->Location = System::Drawing::Point(126, 495);
			this->gradeStudentNumber->MaxLength = 10;
			this->gradeStudentNumber->Name = L"gradeStudentNumber";
			this->gradeStudentNumber->Size = System::Drawing::Size(203, 20);
			this->gradeStudentNumber->TabIndex = 11;
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(335, 495);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(47, 19);
			this->label5->TabIndex = 16;
			this->label5->Text = L"grade";
			// 
			// grade
			// 
			this->grade->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->grade->BackColor = System::Drawing::SystemColors::Window;
			this->grade->Location = System::Drawing::Point(388, 496);
			this->grade->MaxLength = 2;
			this->grade->Name = L"grade";
			this->grade->Size = System::Drawing::Size(33, 20);
			this->grade->TabIndex = 15;
			// 
			// textbookBox
			// 
			this->textbookBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textbookBox->BackColor = System::Drawing::SystemColors::Window;
			this->textbookBox->Location = System::Drawing::Point(12, 152);
			this->textbookBox->MaxLength = 100;
			this->textbookBox->Name = L"textbookBox";
			this->textbookBox->Size = System::Drawing::Size(258, 20);
			this->textbookBox->TabIndex = 11;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label3->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(72, 12);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(388, 44);
			this->label3->TabIndex = 50;
			this->label3->Text = L"LOGO UNIVERISITY";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(16, 12);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(50, 44);
			this->pictureBox2->TabIndex = 49;
			this->pictureBox2->TabStop = false;
			// 
			// iCourse
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(692, 560);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->textbookBox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->grade);
			this->Controls->Add(this->gradeError);
			this->Controls->Add(this->gradeButton);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->addCommentButton);
			this->Controls->Add(this->gradeStudentNumber);
			this->Controls->Add(this->commentBox);
			this->Controls->Add(this->studentList);
			this->Controls->Add(this->changeTextbook);
			this->Controls->Add(this->textbookLabel);
			this->Controls->Add(this->creditLabel);
			this->Controls->Add(this->titleLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"iCourse";
			this->Text = L"Course";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//comment
private: System::Void addCommentButton_Click(System::Object^ sender, System::EventArgs^ e) {
	string commentText((const char*)(Marshal::StringToHGlobalAnsi(commentBox->Text)).ToPointer());
	MYSQL* con = mysql_init(NULL);
	con = mysql_real_connect(con, "localhost", "root", "password", "logo_university", 3306, NULL, 0);
	if (con) {
		string query = "update course set comment = \"" + commentText + "\" where course_code = \"" + iCourseCodeString + "\";";
		mysql_query(con, query.c_str());
	}
}
	   //grade
private: System::Void gradeButton_Click(System::Object^ sender, System::EventArgs^ e) {
	gradeError->Text = " ";

	string studentNUmberText((const char*)(Marshal::StringToHGlobalAnsi(this->gradeStudentNumber->Text)).ToPointer());
	string gradeText((const char*)(Marshal::StringToHGlobalAnsi(this->grade->Text)).ToPointer());

	if (studentNUmberText == "")
		this->gradeError->Text = "invalid id";
	else if (gradeText == "") {
		this->gradeError->Text = "enter grade";
	}
	else if (gradeText != "A" && gradeText != "A-" && gradeText != "B+" && gradeText != "B" && gradeText != "B-" && gradeText != "C+" && gradeText != "C" && gradeText != "C-" && gradeText != "D+" && gradeText != "D" && gradeText != "D-" && gradeText != "F") {
		gradeError->Text = "invalide grade";
	}
	else {
		MYSQL* con = mysql_init(NULL);
		con = mysql_real_connect(con, "localhost", "root", "password", "logo_university", 3306, NULL, 0);
		if (con) {
			string query = "update takes set grade = \"" + gradeText + "\" where s_id = " + studentNUmberText + " and year = " + to_string(year) +
				" and semester = \"" + isemester + "\" and course_code = \"" + iCourseCodeString + "\";";
			int check = mysql_query(con, query.c_str());
			if (!check) {

				gradeStudentNumber->Text = "";
				grade->Text = "";
			}
		}
	}

}

	   //add student
private: System::Void studentNumberError_Click(System::Object^ sender, System::EventArgs^ e) {
	addStudentError->Text = " ";
	string studentNumberText((const char*)(Marshal::StringToHGlobalAnsi(this->studentNumber->Text)).ToPointer());
	if (studentNumberText == "") {
		addStudentError->Text = "invalid id";
	}
	else {
		MYSQL* con = mysql_init(NULL);
		con = mysql_real_connect(con, "localhost", "root", "password", "logo_university", 3306, NULL, 0);

		if (con) {
			string query = "select * from student where id = " + studentNumberText + ";";
			int check = mysql_query(con, query.c_str());
			if (!check) {
				
				MYSQL_RES* res = mysql_store_result(con);
				int count = mysql_num_rows(res);
				if (count > 0) {
					query = "select * from takes where s_id = " + studentNumberText + " and year = " + to_string(year) + " and semester = \"" + isemester + "\";";
					check = mysql_query(con, query.c_str());
					if (!check) {
						res = mysql_store_result(con);
						count = mysql_num_rows(res);
						if (count < 6) {
							query = "select prereq_code from prereq where course_code =\"" + iCourseCodeString + "\";";
							check = mysql_query(con, query.c_str());
							if (!check) {

								res = mysql_store_result(con);
								MYSQL_ROW rowPrereq;
								bool checkP = true;
								//

								while ((rowPrereq = mysql_fetch_row(res)) != NULL) {
									query = "select course_code from takes where s_id = " + studentNumberText + ";";
									check = mysql_query(con, query.c_str());
									if (!check) {

										MYSQL_RES* res1 = mysql_store_result(con);
										MYSQL_ROW rowStudent;
										int i = 0;
										checkP = true;
										while ((rowStudent = mysql_fetch_row(res1)) != NULL) {
											if (strcmp(rowStudent[0], rowPrereq[0]) == 0) {
												i = 1;
												break;
											}
										}
										if (i == 0) {
											checkP = false;
											addStudentError->Text = "a prereq is missing";
											break;
										}
									}
								}
								if (checkP) {
									string query = "select course_code from section where course_code = \"" + iCourseCodeString + "\" and year = " + to_string(year)
										+ " and semester = \"" + isemester + "\";";

									int check = mysql_query(con, query.c_str());
									if (!check) {
										MYSQL_RES* res = mysql_store_result(con);
										MYSQL_ROW row;
										int count = mysql_num_rows(res);
										int i;
										for (i = 0; i < count; i++) {
											query = "select capacity from section, classroom where section.building = classroom.building and section.room_number = classroom.room_number"
												" and course_code = \"" + iCourseCodeString + "\" and year = " + to_string(year) + " and group_number = " + to_string(i + 1) + ";";
											mysql_query(con, query.c_str());
											res = mysql_store_result(con);
											row = mysql_fetch_row(res);
											int capacity = atoi(row[0]);
											
											//student count in that group
											query = "select s_id from takes where course_code = \"" + iCourseCodeString + "\" and year = " + to_string(year) + " and group_number = " + to_string(i + 1) + ";";
											mysql_query(con, query.c_str());
											res = mysql_store_result(con);
											int count_students = mysql_num_rows(res);
											if (count_students < capacity) {
												query = " insert ignore into takes values ( " + studentNumberText + ",\"" + iCourseCodeString + "\"," + to_string(i + 1) + ",\""
													+ isemester + "\"," + to_string(year) + ", \"*\");";
												mysql_query(con, query.c_str());
												studentNumber->Text = "";
												addStudentError->Text = "success";
												break;
											}
										}
										if (i == count) {
											addStudentError->Text = "out of space";
										}
									}
								}

							}
						}
						else {
							addStudentError->Text = "student has reached the course limit";
						}
					}
				}
				else {
					addStudentError->Text = "invalid id";

				}
			}
		}
	}
}
private: System::Void changeTextbook_Click(System::Object^ sender, System::EventArgs^ e) {
	string textBooktext((const char*)(Marshal::StringToHGlobalAnsi(this->textbookBox->Text)).ToPointer());
	MYSQL* con = mysql_init(NULL);
	con = mysql_real_connect(con, "localhost", "root", "password", "logo_university", 3306, NULL, 0);
	if (con) {
		string query = "update course set textbook = \"" + textBooktext + "\" where course_code = \"" + iCourseCodeString + "\";";
		mysql_query(con, query.c_str());
	}
}
};
}
