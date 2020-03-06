# VisualSkillEditor
一种基于指令集的技能系统：将技能抽象为基于时间轴的主线（也支持控制逻辑和跳转），通过在时间轴上挂接技能指令的方式来表达技能逻辑。
提供以下特性：
1.提供30+条指令，全部为瞬发指令，基本满足正交性，各自独立且便于扩展；
2.使用xml格式来保存技能逻辑，同时提供一套标准化的解析和执行运行时；
3.可视化编辑，在编辑器中拖拽指令和控制结构，一目了然；

A skill editor based on instruction set: abstract skills as the time-line stream supporting flow control(selection and jumps). It's designed to let designer express skill ideas by attaching skill instructions on the time stream. 
Provides the following features:
1.Provide 30+ instructions, all of which are instant instructions, basically meet the orthogonality, are independent and easy to expand;
2.Use xml format to save skill, while providing a standardized set of parsing and execution runtimes;
3.Visual editing, dragging instructions and control structures in the editor at a glance;
