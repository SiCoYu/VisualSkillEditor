1.����pro�ļ�
visual studio�����У�ѡ��sloution���Ҽ����"create base pro"

2.��pro�ļ������
TRANSLATIONS += I18N/en.ts \
                I18N/zh.ts

3.��  Qt 5.6.3 64-bit for Desktop (MSVC 2013)
  ��ת��pro����Ŀ¼
  
4.��cmd��ִ�����
lupdate -verbose SkillEditor.pro

5.�����Է��빤��
linguist 

6.����.qm�ļ���.qm�Ǿ���.tsת�����ɵĶ����ƻ������ԣ�
lrelease �Cverbose SkillEditor.pro


