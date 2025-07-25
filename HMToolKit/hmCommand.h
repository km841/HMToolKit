#pragma once
class hmObject;

#define hmAllEventsMacro()                                                                        \
    _hm_add_event(AnyEvent)                                                                       \
    _hm_add_event(DeleteEvent)                                                                    \
    _hm_add_event(StartEvent)                                                                     \
    _hm_add_event(EndEvent)                                                                       \
    _hm_add_event(RenderEvent)                                                                    \
    _hm_add_event(ProgressEvent)                                                                  \
    _hm_add_event(PickEvent)                                                                      \
    _hm_add_event(StartPickEvent)                                                                 \
    _hm_add_event(EndPickEvent)                                                                   \
    _hm_add_event(AbortCheckEvent)                                                                \
    _hm_add_event(ExitEvent)                                                                      \
    _hm_add_event(LeftButtonPressEvent)                                                           \
    _hm_add_event(LeftButtonReleaseEvent)                                                         \
    _hm_add_event(MiddleButtonPressEvent)                                                         \
    _hm_add_event(MiddleButtonReleaseEvent)                                                       \
    _hm_add_event(RightButtonPressEvent)                                                          \
    _hm_add_event(RightButtonReleaseEvent)                                                        \
    _hm_add_event(EnterEvent)                                                                     \
    _hm_add_event(LeaveEvent)                                                                     \
    _hm_add_event(KeyPressEvent)                                                                  \
    _hm_add_event(KeyReleaseEvent)                                                                \
    _hm_add_event(CharEvent)                                                                      \
    _hm_add_event(ExposeEvent)                                                                    \
    _hm_add_event(ConfigureEvent)                                                                 \
    _hm_add_event(TimerEvent)                                                                     \
    _hm_add_event(MouseMoveEvent)                                                                 \
    _hm_add_event(MouseWheelForwardEvent)                                                         \
    _hm_add_event(MouseWheelBackwardEvent)                                                        \
    _hm_add_event(ActiveCameraEvent)                                                              \
    _hm_add_event(CreateCameraEvent)                                                              \
    _hm_add_event(ResetCameraEvent)                                                               \
    _hm_add_event(ResetCameraClippingRangeEvent)                                                  \
    _hm_add_event(ModifiedEvent)                                                                  \
    _hm_add_event(WindowLevelEvent)                                                               \
    _hm_add_event(StartWindowLevelEvent)                                                          \
    _hm_add_event(EndWindowLevelEvent)                                                            \
    _hm_add_event(ResetWindowLevelEvent)                                                          \
    _hm_add_event(SetOutputEvent)                                                                 \
    _hm_add_event(ErrorEvent)                                                                     \
    _hm_add_event(WarningEvent)                                                                   \
    _hm_add_event(StartInteractionEvent)                                                          \
    _hm_add_event(DropFilesEvent)                                                                 \
    _hm_add_event(UpdateDropLocationEvent)                                                        \
        /*^ mainly used by vtkInteractorObservers*/                                                \
    _hm_add_event(InteractionEvent)                                                               \
    _hm_add_event(EndInteractionEvent)                                                            \
    _hm_add_event(EnableEvent)                                                                    \
    _hm_add_event(DisableEvent)                                                                   \
    _hm_add_event(CreateTimerEvent)                                                               \
    _hm_add_event(DestroyTimerEvent)                                                              \
    _hm_add_event(PlacePointEvent)                                                                \
    _hm_add_event(DeletePointEvent)                                                               \
    _hm_add_event(PlaceWidgetEvent)                                                               \
    _hm_add_event(CursorChangedEvent)                                                             \
    _hm_add_event(ExecuteInformationEvent)                                                        \
    _hm_add_event(RenderWindowMessageEvent)                                                       \
    _hm_add_event(WrongTagEvent)                                                                  \
    _hm_add_event(StartAnimationCueEvent)                                                         \
    _hm_add_event(ResliceAxesChangedEvent)                                                        \
        /*^ used by vtkAnimationCue*/                                                              \
    _hm_add_event(AnimationCueTickEvent)                                                          \
    _hm_add_event(EndAnimationCueEvent)                                                           \
    _hm_add_event(VolumeMapperRenderEndEvent)                                                     \
    _hm_add_event(VolumeMapperRenderProgressEvent)                                                \
    _hm_add_event(VolumeMapperRenderStartEvent)                                                   \
    _hm_add_event(VolumeMapperComputeGradientsEndEvent)                                           \
    _hm_add_event(VolumeMapperComputeGradientsProgressEvent)                                      \
    _hm_add_event(VolumeMapperComputeGradientsStartEvent)                                         \
    _hm_add_event(WidgetModifiedEvent)                                                            \
    _hm_add_event(WidgetValueChangedEvent)                                                        \
    _hm_add_event(WidgetActivateEvent)                                                            \
    _hm_add_event(ConnectionCreatedEvent)                                                         \
    _hm_add_event(ConnectionClosedEvent)                                                          \
    _hm_add_event(DomainModifiedEvent)                                                            \
    _hm_add_event(PropertyModifiedEvent)                                                          \
    _hm_add_event(UpdateEvent)                                                                    \
    _hm_add_event(RegisterEvent)                                                                  \
    _hm_add_event(UnRegisterEvent)                                                                \
    _hm_add_event(UpdateInformationEvent)                                                         \
    _hm_add_event(AnnotationChangedEvent)                                                         \
    _hm_add_event(SelectionChangedEvent)                                                          \
    _hm_add_event(UpdatePropertyEvent)                                                            \
    _hm_add_event(ViewProgressEvent)                                                              \
    _hm_add_event(UpdateDataEvent)                                                                \
    _hm_add_event(CurrentChangedEvent)                                                            \
    _hm_add_event(ComputeVisiblePropBoundsEvent)                                                  \
    _hm_add_event(TDxMotionEvent)                                                                 \
      /*^ 3D Connexion device event */                                                             \
    _hm_add_event(TDxButtonPressEvent)                                                            \
      /*^ 3D Connexion device event */                                                             \
    _hm_add_event(TDxButtonReleaseEvent)                                                          \
      /* 3D Connexion device event */                                                              \
    _hm_add_event(HoverEvent)                                                                     \
    _hm_add_event(LoadStateEvent)                                                                 \
    _hm_add_event(SaveStateEvent)                                                                 \
    _hm_add_event(StateChangedEvent)                                                              \
    _hm_add_event(WindowMakeCurrentEvent)                                                         \
    _hm_add_event(WindowIsCurrentEvent)                                                           \
    _hm_add_event(WindowFrameEvent)                                                               \
    _hm_add_event(HighlightEvent)                                                                 \
    _hm_add_event(WindowSupportsOpenGLEvent)                                                      \
    _hm_add_event(WindowIsDirectEvent)                                                            \
    _hm_add_event(WindowStereoTypeChangedEvent)                                                   \
    _hm_add_event(WindowResizeEvent)                                                              \
    _hm_add_event(UncheckedPropertyModifiedEvent)                                                 \
    _hm_add_event(UpdateShaderEvent)                                                              \
    _hm_add_event(MessageEvent)                                                                   \
    _hm_add_event(StartSwipeEvent)                                                                \
    _hm_add_event(SwipeEvent)                                                                     \
    _hm_add_event(EndSwipeEvent)                                                                  \
    _hm_add_event(StartPinchEvent)                                                                \
    _hm_add_event(PinchEvent)                                                                     \
    _hm_add_event(EndPinchEvent)                                                                  \
    _hm_add_event(StartRotateEvent)                                                               \
    _hm_add_event(RotateEvent)                                                                    \
    _hm_add_event(EndRotateEvent)                                                                 \
    _hm_add_event(StartPanEvent)                                                                  \
    _hm_add_event(PanEvent)                                                                       \
    _hm_add_event(EndPanEvent)                                                                    \
    _hm_add_event(TapEvent)                                                                       \
    _hm_add_event(LongTapEvent)                                                                   \
    _hm_add_event(FourthButtonPressEvent)                                                         \
    _hm_add_event(FourthButtonReleaseEvent)                                                       \
    _hm_add_event(FifthButtonPressEvent)                                                          \
    _hm_add_event(FifthButtonReleaseEvent)                                                        \
    _hm_add_event(Move3DEvent)                                                                    \
    _hm_add_event(Button3DEvent)                                                                  \
    _hm_add_event(TextEvent)                                                                      \
    _hm_add_event(LeftButtonDoubleClickEvent)                                                     \
    _hm_add_event(MiddleButtonDoubleClickEvent)                                                   \
    _hm_add_event(RightButtonDoubleClickEvent)                                                    \
    _hm_add_event(MouseWheelLeftEvent)                                                            \
    _hm_add_event(MouseWheelRightEvent)                                                           \
    _hm_add_event(ViewerMovement3DEvent)                                                          \
    _hm_add_event(Menu3DEvent)                                                                    \
    _hm_add_event(NextPose3DEvent)                                                                \
    _hm_add_event(Clip3DEvent)                                                                    \
    _hm_add_event(PositionProp3DEvent)                                                            \
    _hm_add_event(Pick3DEvent)                                                                    \
    _hm_add_event(Select3DEvent)                                                                  \
    _hm_add_event(Elevation3DEvent)
// clang-format on

#define hmEventDeclarationMacro(_enum_name)                                                       \
  enum _enum_name                                                                                  \
  {                                                                                                \
    NoEvent = 0,                                                                                   \
    hmAllEventsMacro() UserEvent = 1000                                                           \
  }

class hmCommand
{
public:
	virtual void Execute(hmObject* caller, unsigned long eventId, void* callData) = 0;

	static const char* GetStringFromEventId(unsigned int event);
	static unsigned int GetEventIdFromString(const char* event);

	static bool EventHasData(unsigned long event);

	void SetAbortFlag(hmTypeBool f) { this->AbortFlag = f; }
	hmTypeBool GetAbortFlag() { return this->AbortFlag; }

	void AbortFlagOn() { this->SetAbortFlag(1); }
	void AbortFlagOff() { this->SetAbortFlag(0); }

	void SetPassiveObserver(hmTypeBool f) { this->PassiveObserver = f; }
	hmTypeBool GetPassiveObserver() { return this->PassiveObserver; }

	void PassiveObserverOn() { return this->SetPassiveObserver(1); }
	void PassiveObserverOff() { return this->SetPassiveObserver(0); }

#define _hm_add_event(Enum) Enum,
    hmEventDeclarationMacro(EventIds);
#undef _hm_add_event

protected:
	hmCommand();
	virtual ~hmCommand() = default;

protected:
	hmTypeBool AbortFlag;
	hmTypeBool PassiveObserver;

	
};

