local cls = class(M)
cls.CPPCLS = "fairygui::GProgressBar"
cls.LUACLS = "fgui.GProgressBar"
cls.SUPERCLS = "fgui.GComponent"
cls.funcs [[
    static GProgressBar *create()
    ProgressTitleType getTitleType()
    void setTitleType(ProgressTitleType value)
    double getMax()
    void setMax(double value)
    double getValue()
    void setValue(double value)
    void tweenValue(double value, float duration)
]]
cls.props [[
    titleType
    max
    value
]]

return cls