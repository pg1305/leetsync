class Spreadsheet {
    unordered_map<string, int> cells;
public:
    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        cells[cell] = value;
    }
    
    void resetCell(string cell) {
        cells.erase(cell);
    }
    
    int getValue(string formula) {
        int i = formula.find('+');
        string left = formula.substr(1, i - 1);
        string right = formula.substr(i + 1);
        int valL = isalpha(left[0]) ? (cells.count(left) ? cells[left]:0) : stoi(left);
        int valR = isalpha(right[0]) ? (cells.count(right) ? cells[right]:0) : stoi(right);
        return valL + valR;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */