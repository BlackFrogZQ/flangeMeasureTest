#pragma once

const QString cStyleSheet = "border:1px groove gray;\n"                  // 1px 凹槽灰色边框
                            "border-radius:10px;\n"                      // 10像素圆角半径
                            "padding:2px 3px;\n"                         // 内边距（垂直2px，水平3px）
                            "background:transparent;\n"                  // 背景透明（可能被后续覆盖）
                            "background-color: rgb(255, 255, 255,150);"; // 白色半透明背景（alpha=150）
const QString cMainStyleSheet = "background-color: #2E2F30;";

const QString VmFrontendControlWinform = "{32DB9666-8D63-471A-ADD9-1A7013D8DEC6}"; // 前端控制窗口
const QString VmGlobalToolWinform = "{B60D44E7-1726-42AA-9ED5-D5D512A6C1F2}"; // 全局工具窗口
const QString VmMainViewControlWinform = "{650FFBDC-5E28-4314-8901-7F02E6145414}"; // 主视图控制窗口
const QString VmParamsControlWinform = "{10C9ADFD-ABB2-4AB3-BAB4-26E568D12F1F}"; // 参数块控制窗口
const QString VmParamsRenderControlWinform = "{C6961180-1F47-41A2-82A6-D9811887F4F6}"; // 参数渲染控制窗口
const QString VmProcedureControlWinform = "{4919FA4C-F224-4C1E-917C-89B7F37AAE90}"; // 方案控制窗口  SolutionControl
const QString VmRealTimeAcqControlWinform = "{4919FA4C-F224-4C1E-917C-89B7F37AAE00}"; // 实时采集控制窗口
const QString VmRenderControlWinform = "{313241A6-62F9-464B-BEDE-F514827E2F4B}"; // 渲染控制窗口
const QString VmSingleModulesetControlWinform = "{0611E76E-3E97-42C7-8D2D-A8A42E928A7A}"; // 单模块控制窗口