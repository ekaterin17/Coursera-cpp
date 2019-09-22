//#include <list>
//#include <string>
//
//#include "test_runner.h"
//using namespace std;
//
//class Editor {
//public:
//    Editor() : cursor_pos(text.begin()) {};
//
//    void Left() {
//        if (cursor_pos != text.begin()) {
//            --cursor_pos;
//        }
//    }
//
//    void Right() {
//        if (cursor_pos != text.end()) {
//            ++cursor_pos;
//        }
//    }
//
//    void Insert(char token) {
//        text.insert(cursor_pos, token);
//    }
//
//    void Copy(size_t tokens) {
//        buffer.assign(cursor_pos, MoveIterator(tokens));
//    }
//
//    void Cut(size_t tokens) {
//        buffer.clear();
//        auto it = MoveIterator(tokens);
//        buffer.splice(buffer.begin(), text, cursor_pos, it);
//        cursor_pos = it;
//    }
//    void Paste() {
//        text.insert(cursor_pos, buffer.begin(), buffer.end());
//    }
//
//    string GetText() const {
//        ostringstream os;
//        for (auto it = text.begin(); it != text.end(); ++it) {
//            os << *it;
//        }
//        return os.str();
//    }
//private:
//    list<char> text;
//    list<char> buffer;
//    list<char>::iterator cursor_pos;
//
//    list<char>::iterator MoveIterator(size_t tokens) {
//        list<char>::iterator pos = cursor_pos;
//        size_t count = 0;
//        for (; pos != text.end() && count < tokens; ++pos, ++count) {}
//        return pos;
//    }
//};
//
//void TypeText(Editor& editor, const string& text) {
//    for(char c : text) {
//        editor.Insert(c);
//    }
//}
//
//void TestEditing() {
//    {
//        Editor editor;
//
//        const size_t text_len = 12;
//        const size_t first_part_len = 7;
//        TypeText(editor, "hello, world");
//        for(size_t i = 0; i < text_len; ++i) {
//            editor.Left();
//        }
//        editor.Cut(first_part_len);
//        for(size_t i = 0; i < text_len - first_part_len; ++i) {
//            editor.Right();
//        }
//        TypeText(editor, ", ");
//        editor.Paste();
//        editor.Left();
//        editor.Left();
//        editor.Cut(3);
//
//        ASSERT_EQUAL(editor.GetText(), "world, hello");
//    }
//    {
//        Editor editor;
//
//        TypeText(editor, "misprnit");
//        editor.Left();
//        editor.Left();
//        editor.Left();
//        editor.Cut(1);
//        editor.Right();
//        editor.Paste();
//
//        ASSERT_EQUAL(editor.GetText(), "misprint");
//    }
//}
//
//void TestReverse() {
//    Editor editor;
//
//    const string text = "esreveR";
//    for(char c : text) {
//        editor.Insert(c);
//        editor.Left();
//    }
//
//    ASSERT_EQUAL(editor.GetText(), "Reverse");
//}
//
//void TestNoText() {
//    Editor editor;
//    ASSERT_EQUAL(editor.GetText(), "");
//
//    editor.Left();
//    editor.Left();
//    editor.Right();
//    editor.Right();
//    editor.Copy(0);
//    editor.Cut(0);
//    editor.Paste();
//
//    ASSERT_EQUAL(editor.GetText(), "");
//}
//
//void TestEmptyBuffer() {
//    Editor editor;
//
//    editor.Paste();
//    TypeText(editor, "example");
//    editor.Left();
//    editor.Left();
//    editor.Paste();
//    editor.Right();
//    editor.Paste();
//    editor.Copy(0);
//    editor.Paste();
//    editor.Left();
//    editor.Cut(0);
//    editor.Paste();
//
//    ASSERT_EQUAL(editor.GetText(), "example");
//}
//
//int main() {
//    TestRunner tr;
//    RUN_TEST(tr, TestEditing);
//    RUN_TEST(tr, TestReverse);
//    RUN_TEST(tr, TestNoText);
//    RUN_TEST(tr, TestEmptyBuffer);
//    return 0;
//}
