#define _CRT_SECURE_NO_WARNINGS
#include "MyFrame.h"
#include <time.h>
using namespace std;
MyFrame::MyFrame(wstring title): Frame(title){}
MyFrame::MyFrame(wstring title, int x, int y): Frame(title,x,y){}

void MyFrame::run() {
	InterfaceUpdate();   
	Frame::run();
}
//초기 인터페이스를 불러옵니다.
void MyFrame::InterfaceUpdate() {
	Debug("초기화\n");
	pShape_ = new list<MyShape*>;
	setFont(15, RGB(240, 240, 240));
	setColor(RGB(100, 100, 100),RGB(45, 45, 45)); //전체 색 지정
	COLORREF p = RGB(100, 100, 100);
	COLORREF b = RGB(45, 45, 45);
	/*__다이얼로그__________________________________________________________*/
	Box* dialog = new Box;
	addWindow(dialog);

	DialogueListener* lis_dia = new DialogueListener(this);
	load_dir = new TextPutDialogue(hdc_, "< 불러오기 >", 400, 200);
	dialog->addWindow(load_dir);
	load_dir->addWorkButton(new TextButton(hdc_, "취소", 100, 30, p, b));
	load_dir->addWorkButton(new TextButton(hdc_, "불러오기", 100, 30, p, b, lis_dia));
	load_dir->enterText("이전 작업한 내용이 전부 삭제됩니다.");
	load_dir->enterText("불러올 파일 이름을 입력해주세요.");
	TextLabel* tl = new TextLabel(hdc_, "", 330, 30, 0);
	tl->setColor(RGB(100, 100, 100), RGB(65, 65, 65));
	load_dir->addTextLabel(tl);

	help_dir = new TextDialogue(hdc_, "< 도움말 >", 400, 300);
	dialog->addWindow(help_dir);
	help_dir->addWorkButton(new TextButton(hdc_, "확인", 100, 30));
	help_dir->enterText("저장 : 파일 -> 저장");
	help_dir->enterText("열기 : 파일 -> 열기 ");
	help_dir->enterText("도형선택 : 도형버튼 선택");
	help_dir->enterText("색 선택 : 선색/채우기색 -> 색");
	help_dir->enterText("모두 지우기 : 지우기 선택");
	help_dir->enterText("복사-붙여넣기 : ctrl + 클릭 ");
	help_dir->enterText("도형선택이동: shift + 클릭 ");

	save_dir = new TextPutDialogue(hdc_, "< 저장하기 >", 400, 200);
	dialog->addWindow(save_dir);
	save_dir->addWorkButton(new TextButton(hdc_, "취소", 100, 30));
	save_dir->addWorkButton(new TextButton(hdc_, "저장하기", 100, 30, p,b, lis_dia));
	save_dir->enterText("작업 내용을 전부 저장합니다.");
	save_dir->enterText("저장할 파일 이름을 입력해주세요.");
	TextLabel* tx = new TextLabel(hdc_, "", 330, 30, 0);
	tx->setColor(RGB(100, 100, 100), RGB(65, 65, 65));
	save_dir->addTextLabel(tx);



	/*__메뉴__________________________________________________________________*/
	MenuBar* pMenu = new MenuBar(hdc_);
	addWindow(pMenu);
	
	MenuListener* lis_menu = new MenuListener(this); //타입 리스너
	Menu* pm1 = new Menu(hdc_, "파일", 100, 30, p, b); //파일메뉴
	pMenu->addWindow(pm1);
	pm1->addWindow(new TextButton(hdc_, "새로 만들기", 100, 30, p, b, lis_menu));
	pm1->addWindow(new TextButton(hdc_, "저장", 100, 30, p, b, lis_menu));
	pm1->addWindow(new TextButton(hdc_, "열기", 100, 30, p, b, lis_menu));
	pm1->addWindow(new TextButton(hdc_, "종료", 100, 30, p, b, lis_menu));

	
	Menu* pMtb = new Menu(hdc_, "도구", 100, 30, p, b); //도형
	pMenu->addWindow(pMtb);
	TypeListener* lis_tool1 = new TypeListener(this); //타입 리스너
	pMtb->addWindow(new TextButton(hdc_, "펜", 100, 30, p, b, lis_tool1));
	pMtb->addWindow(new TextButton(hdc_, "사각형", 100, 30, p, b, lis_tool1));
	pMtb->addWindow(new TextButton(hdc_, "선분", 100, 30, p, b, lis_tool1));
	pMtb->addWindow(new TextButton(hdc_, "원", 100, 30, p, b, lis_tool1));
	pMtb->addWindow(new TextButton(hdc_, "지우기", 100, 30, p, b, lis_tool1));

	Menu* pMhelp = new Menu(hdc_, "도움말", 100, 30, p, b); //도움말
	pMenu->addWindow(pMhelp);
	pMhelp->addWindow(new TextButton(hdc_, "사용법", 100, 30, p, b, lis_menu));


	/*__도구 툴바 _______________________________________________________________*/
	ToolBar* pMTool_ = new ToolBar;
	addWindow(pMTool_);

	TypeListener* lis_tool = new TypeListener(this); //타입 리스너
	Button* t1 = new TextButton(hdc_, "펜", 100, 30, p, b, lis_tool);
	Button* t2 = new TextButton(hdc_, "사각형", 100, 30, p, b, lis_tool);
	Button* t3 = new TextButton(hdc_, "선분", 100, 30, p, b, lis_tool);
	Button* t4 = new TextButton(hdc_, "원", 100, 30, p, b, lis_tool);
	Button* t5 = new TextButton(hdc_, "지우기", 100, 30, p, b, lis_tool);
	t1->setsts(pm1);
	t2->setsts(pMtb);
	t3->setsts(pMhelp);
	pMTool_->addWindow(t1);
	pMTool_->addWindow(t2);
	pMTool_->addWindow(t3);
	pMTool_->addWindow(t4);
	pMTool_->addWindow(t5);
	
	/*____색깔____________________________________________________________________*/
	ToolBar* pMcol = new ToolBar;
	addWindow(pMcol);
	Button* pc = new TextButton(hdc_, "선색", 70, 30, p, b, lis_tool);
	pMcol->addWindow(pc);
	pbox = new ColorBox(hdc_, "pbox", 30, 30, RGB(0, 0, 0));
	pMcol->addWindow(pbox);
	Button* bc = new TextButton(hdc_, "채우기색", 100, 30, p, b, lis_tool);
	pMcol->addWindow(bc);
	bbox = new ColorBox(hdc_, "bbox", 30, 30, RGB(255, 255, 255));
	pMcol->addWindow(bbox);
	pc->setsts(pm1);
	bc->setsts(pMtb);
	pbox->setsts(pm1);

	ValueListener* lis_option = new ValueListener(this);
	pMcol->addWindow(new TextLabel(hdc_, "색", 30, 30));
	pMcol->addWindow(new ColorBox(hdc_, 30, 30, RGB(0, 0, 0), lis_option));
	pMcol->addWindow(new ColorBox(hdc_, 30, 30, RGB(255, 255, 255),lis_option));
	pMcol->addWindow(new ColorBox(hdc_, 30, 30, RGB(237, 28, 36), lis_option));
	pMcol->addWindow(new ColorBox(hdc_, 30, 30, RGB(255, 120, 40),lis_option));
	pMcol->addWindow(new ColorBox(hdc_, 30, 30, RGB(255, 245, 0), lis_option));
	pMcol->addWindow(new ColorBox(hdc_, 30, 30, RGB(132, 240, 109), lis_option));
	pMcol->addWindow(new ColorBox(hdc_, 30, 30, RGB(34, 177, 76), lis_option));
	pMcol->addWindow(new ColorBox(hdc_, 30, 30, RGB(0, 162, 232), lis_option));
	pMcol->addWindow(new ColorBox(hdc_, 30, 30, RGB(63, 72, 204), lis_option));
	pMcol->addWindow(new ColorBox(hdc_, 30, 30, RGB(163, 73, 164), lis_option));

	pMcol->addWindow(new TextLabel(hdc_, "두께", 50, 30));
	wide_label = new TextLabel(hdc_, "", 30, 30, 1);
	wide_label->setValue(1);
	pMcol->addWindow(wide_label);
	pMcol->addWindow(new TextButton(hdc_, "＋", 30, 30, p, b, lis_option));
	pMcol->addWindow(new TextButton(hdc_, "－", 30, 30, p, b, lis_option));
	
	/*________________________________________________________________________*/
	addLayout(new FlowLayout(this));
	PaintingType = "펜";
	arrangeLayout();
	repaintAll();
}

/* 프로세스 */
bool MyFrame::processMessage(MyEvent e) {
	if (!(Frame::processMessage(e)))         //툴바 이벤트를 처리합니다.
	{                                        //응용
		switch (e.event_type_) {
		case WM_LBUTTONDOWN:
		{
			startx = e.x_, starty = e.y_;    //좌표저장

			if (e.isShiftPressed()) {        //쉬프트-도형선택 : 이동
				if (selectShape(e))
					Action = MOVE_ACTION;
			}
			else if (e.isContolPressed()) {  //컨트롤-도형선택 : 복사
				if (selectShape(e))
					Action = CAPY_ACTION;
			}
			else if (PaintingType =="펜") {
				Pen_line = new Group;
				PenType = TRUE;
			}
		} break;
		case WM_LBUTTONUP:
		{
			if (Action == MOVE_ACTION && e.isShiftPressed()) { 
				MoveAction(e);               //도형 이동
				repaintAll();
			}
			else if (Action == CAPY_ACTION && e.isContolPressed()) {
				capyAction(e);               //도형 복사
			}
			else if (PaintingType == "펜") {
				pShape_->push_back(Pen_line);
				PenType = FALSE;
			}
			else {
				drawAction(e);               //그림을 그립니다.
			}
			Action = DRAW_ACTION;
			repaint();
		} break;
		case WM_RBUTTONDOWN:
		{
			startx = e.x_, starty = e.y_;
		} break;
		case WM_RBUTTONUP:
		{
			groupAction(e);                  //도형 그룹화
			repaint();
		} break;
		case WM_MOUSEMOVE:
		{
			if (PenType) {                   //팬으로 그립니다.
				MyLine* lin = new MyLine(hdc_, startx, starty, e.x_, e.y_);
				lin->setColar(Pen_color, Brush_color, Line_wid); //도형의 색을 지정합니다.
				Pen_line->AddGroup(lin);
				startx = e.x_, starty = e.y_;
			}
		}break;
		default: 	break;
		}
	}
	return TRUE;
}

/* 도형을 선택합니다. */
bool MyFrame::selectShape(MyEvent e) { 
	list<MyShape*>::iterator it; 
	int state = FALSE;
	for (it = pShape_->begin(); it != pShape_->end(); it++)
	{
		if ((*it)->isShapeArea(e)) {          //도형을 선택했다면
			pTemp = it;
			state = TRUE;
		}
	}
	return state;
}

/* 도형을 이동합니다. */
void MyFrame::MoveAction(MyEvent e) {
	Debug("Move Shape.\n");
	(*pTemp)->MoveShape(startx, starty, e.x_, e.y_);
}

/* 도형을 복사합니다. */
void MyFrame::capyAction(MyEvent e) {
	Debug("Capy Shape.\n");
	MyShape* capy_shape = (*pTemp)->CapyShape(); //똑같은 도형을 복사합니다.
	pShape_->push_back(capy_shape);
	capy_shape->MoveShape(startx, starty, e.x_, e.y_);
}

/* 도형을 그룹화 합니다. */
void MyFrame::groupAction(MyEvent e) {
	int State = FALSE;
	Group* temp_Group = new Group; //임시 그룹 포인터
	for (auto shp : *pShape_)
	{
		if (shp->isSelectShape(startx, starty, e.x_, e.y_)) {//선택된도형을
			State = TRUE;
			temp_Group->AddGroup(shp); //임시 그룹에 넣습니다.
		}
	}
	if (State) {   //만약 그룹이 만들어졌다면
		Debug("Grouping Shape\n");
		for (auto gp : *temp_Group->List_) {
			pShape_->remove(gp); //기존 그룹에 있던것을 삭제합니다.
		}
		pShape_->push_back(temp_Group); //그룹을 추가합니다.
	}
}

/* 도형을 그립니다. */
void MyFrame::drawAction(MyEvent e) { //페인트 타입에 따라 그림이 결정됩니다.
	MyShape* shape;
	if (PaintingType == "") return;
	Debug("Painting.");
	if (PaintingType == "사각형") {
		Debug(" | 사각형\n");
		shape = new MyRect(hdc_, startx, starty, e.x_, e.y_);
	}
	else if (PaintingType == "선분") {
		Debug(" | 선분\n");
		shape = new MyLine(hdc_, startx, starty, e.x_, e.y_);
	}
	else if (PaintingType == "원") {
		Debug(" | 원\n");
		shape = new MyCircle(hdc_, startx, starty, e.x_, e.y_);
	}
	pShape_->push_back(shape);  //도형을 리스트에 넣고
	shape->setColar(Pen_color,Brush_color,Line_wid); //도형의 색을 지정합니다.
}

/* 모두 삭제합니다. */
void MyFrame::clearAction() {
	delete pShape_;               //삭제하고
	pShape_ = new list<MyShape*>; //다시 리스트 제작
}

/* 버튼 이벤트를 처리합니다.
->리스너를 사용하고 있으니 콜백함수는 지금 필요 없다.  */
void MyFrame::processButtonEvent(Button* pBtn) { 
	//std::string btn_name = pBtn->getTitle();
	/*
	if (btn_name == "사각형"|| btn_name == "원"|| btn_name == "선분"|| btn_name == "펜") {
		PaintingType = btn_name;
	}
	
	 if (btn_name == "채우기색") {
		ColorType = 0;
	}
	else if (btn_name == "선색") {
		ColorType = 1;
	}
	*/
	/*
	if (btn_name == "ColorBox") {
		select_color = pBtn->getColor();
		if (ColorType == 1) { //선색
			Pen_color = select_color;
			((ColorBox*)pbox)->setColor(select_color);
		}
		else if((ColorType == 0)) { //채우기색
			Brush_color = select_color; 
			((ColorBox*)bbox)->setColor(select_color);
		}
	}
	else if (btn_name == "＋") {
		if (Line_wid < 10) {
			Line_wid++;
			wide_label->setValue(Line_wid);
		}
	}
	else if (btn_name == "－") {
		if (Line_wid > 1) {
			Line_wid--;
			wide_label->setValue(Line_wid);
		}
	}
	*/
	/*__ 메뉴 클릭 ____________________________________________________________*/
	/*
	if (btn_name == "저장") {
		save_dir->callDialogue(130, 130);
	}
	
	
	if (btn_name == "저장하기") {
		saveObject();
	}
	
	else if (btn_name == "열기") {
		load_dir->callDialogue(150, 150);
	}
	
	
	else if (btn_name == "불러오기") {
		clearAction();
		loadObject();
	}
	
	 
	else if (btn_name == "지우기") {
		clearAction();
	}
	
	
	else if (btn_name == "새로 만들기") {
		clearAction();
	}
	else if (btn_name == "종료") {
		exit(1);
	}
	else if (btn_name == "사용법") {
		help_dir->callDialogue(150, 100);
	}
	*/
	repaintAll();
}

/* 저장합니다. */
void MyFrame::saveObject() {
	std::string s = save_dir->getTitle();
	save_dir->setTitle("");
	if (s == "") {
		s = "..//save_file/save.txt";
	}
	else {
		s = "..//save_file/" + s + ".txt";
	}

	FILE* fp;
	fp = fopen(s.c_str(), "wt");
	if (fp == NULL)
		throw(1);
	for (auto wl: *pShape_) {
		wl->SaveShape(fp);
	}
	fclose(fp);
}

/* 불러옵니다. */
void MyFrame::loadObject() { //불러오기
	std::string s = load_dir->getTitle();
	load_dir->setTitle("");
	if (s == "") {
		s = "..//save_file/save.txt";
	}
	else {
		s = "..//save_file/" + s + ".txt";
	}
	FILE* fp;
	fp = fopen(s.c_str(), "rt");
	if (fp == NULL)
		throw(1);

	Group* pGr[100];
	int group_side = -1;
	int x1, y1, x2, y2; //좌표   
	char type; //사각형 타입
	COLORREF p_color,b_color; //색 불러오기 임시변수
	int line;

	while (feof(fp) == 0) {  //파일을 모두 읽을떄까지 로드
		if (!fscanf(fp, "%c ", &type))
			throw(1);
		if (type == 'G') {   //그룹 불러오기
			char ba;
			if (!fscanf(fp, "%c\n", &ba))
				throw(1);
			if (ba == '[') {           // [ 그룹 in
				group_side++;
				pGr[group_side] = new Group;
			}
			else if (ba==']') {        // ] 그룹 out
				if (group_side == 0) { //그룹을 리스트에 넣을떄
					pShape_->push_back(pGr[group_side]); 
				}
				else{                  //그룹을 그룹에 넣을떄
					pGr[group_side - 1]->AddGroup(pGr[group_side]);
				}
				group_side--;
			}
		}
		else{
			if (!fscanf(fp, "%d %d %d %d %d %d %d\n", &x1, &y1, &x2, &y2, &p_color, &b_color, &line))
				throw(1);
			MyShape* psh;
			if (type == 'R')
				psh = new MyRect(hdc_, x1, y1, x2, y2);
			else if (type == 'C')
				psh = new MyCircle(hdc_, x1, y1, x2, y2);
			else if (type == 'L')
				psh = new MyLine(hdc_, x1, y1, x2, y2);
			else
				break;
			psh->setColar(p_color, b_color,line);  //그룹에 추가
			if (group_side != -1) {
				pGr[group_side]->AddGroup(psh);
			}
			else {  //리스트에 추가
				pShape_->push_back(psh);
			}
		}
	}
}

/* 그립니다.   */
void MyFrame::repaint() {
	for (auto it : *pShape_) {
		it->repaint();
	}
	Frame::repaint();
}
