#pragma once
#include <QWidget>

class QLineEdit;
class QPushButton;
namespace VisionMasterSDK
{
    namespace VmSolution
    {
        class IVmSolution;
    }
}

class CControl: public QWidget
{
    Q_OBJECT
public:
    CControl(QWidget *parent = nullptr);
    ~CControl();

protected:
	void initLayout();

protected slots:
    void clickSolutionPath();
    void clickLoadSolution();

    void clickImageResults();
    void clickCallBackImageResults();
    void clickProcessResults();

    void clickRenderBind();
    void clickExecuteOnce();
    void clickRenderUnBind();

private:
    QLineEdit *m_LineEditPath;
    QLineEdit *m_LineEditPassword;
    QPushButton *m_pSolutionPath;
    QPushButton *m_pLoadSolution;

    QPushButton *m_pImageResults;
    QPushButton *m_pCallBackImageResults;
    QPushButton *m_pProcessResults;

    QPushButton *m_pRenderBind;
    QPushButton *m_pExecuteOnce;
    QPushButton *m_pRenderUnBind;
    
    VisionMasterSDK::VmSolution::IVmSolution* m_pVmSol;
};
