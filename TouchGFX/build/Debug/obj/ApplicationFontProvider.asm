; Listing generated by Microsoft (R) Optimizing Compiler Version 19.16.27045.0 

	TITLE	D:\stm32_ws\board\JointManipulator_Master\JMM_LCD_V1\JMM_LCD\TouchGFX\generated\fonts\src\ApplicationFontProvider.cpp
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB MSVCRTD
INCLUDELIB OLDNAMES

msvcjmc	SEGMENT
__3F1E7DBE_types@hpp DB 01H
__31EEE322_unicode@hpp DB 01H
__CD7AD2A8_font@hpp DB 01H
__97720798_fontmanager@hpp DB 01H
__A788EF83_applicationfontprovider@hpp DB 01H
__3B3613EC_constfont@hpp DB 01H
__F95B6582_generatedfont@hpp DB 01H
__F3F401AC_texts@hpp DB 01H
__24F62FFF_typedtext@hpp DB 01H
__3F3118DE_applicationfontprovider@cpp DB 01H
msvcjmc	ENDS
PUBLIC	?getFont@ApplicationFontProvider@@UAEPAVFont@touchgfx@@G@Z ; ApplicationFontProvider::getFont
PUBLIC	__JustMyCode_Default
EXTRN	?getFonts@TypedTextDatabase@@YAPAPBVFont@touchgfx@@XZ:PROC ; TypedTextDatabase::getFonts
EXTRN	@__CheckForDebuggerJustMyCode@4:PROC
EXTRN	__RTC_CheckEsp:PROC
EXTRN	__RTC_InitBase:PROC
EXTRN	__RTC_Shutdown:PROC
;	COMDAT rtc$TMZ
rtc$TMZ	SEGMENT
__RTC_Shutdown.rtc$TMZ DD FLAT:__RTC_Shutdown
rtc$TMZ	ENDS
;	COMDAT rtc$IMZ
rtc$IMZ	SEGMENT
__RTC_InitBase.rtc$IMZ DD FLAT:__RTC_InitBase
rtc$IMZ	ENDS
; Function compile flags: /Odt
;	COMDAT __JustMyCode_Default
_TEXT	SEGMENT
__JustMyCode_Default PROC				; COMDAT
	push	ebp
	mov	ebp, esp
	pop	ebp
	ret	0
__JustMyCode_Default ENDP
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
;	COMDAT ?getFont@ApplicationFontProvider@@UAEPAVFont@touchgfx@@G@Z
_TEXT	SEGMENT
tv65 = -208						; size = 4
_this$ = -8						; size = 4
_typography$ = 8					; size = 2
?getFont@ApplicationFontProvider@@UAEPAVFont@touchgfx@@G@Z PROC ; ApplicationFontProvider::getFont, COMDAT
; _this$ = ecx
; File d:\stm32_ws\board\jointmanipulator_master\jmm_lcd_v1\jmm_lcd\touchgfx\generated\fonts\src\applicationfontprovider.cpp
; Line 9
	push	ebp
	mov	ebp, esp
	sub	esp, 208				; 000000d0H
	push	ebx
	push	esi
	push	edi
	push	ecx
	lea	edi, DWORD PTR [ebp-208]
	mov	ecx, 52					; 00000034H
	mov	eax, -858993460				; ccccccccH
	rep stosd
	pop	ecx
	mov	DWORD PTR _this$[ebp], ecx
	mov	ecx, OFFSET __3F3118DE_applicationfontprovider@cpp
	call	@__CheckForDebuggerJustMyCode@4
; Line 10
	movzx	eax, WORD PTR _typography$[ebp]
	mov	DWORD PTR tv65[ebp], eax
	cmp	DWORD PTR tv65[ebp], 5
	ja	SHORT $LN10@getFont
	mov	ecx, DWORD PTR tv65[ebp]
	jmp	DWORD PTR $LN12@getFont[ecx*4]
$LN4@getFont:
; Line 14
	call	?getFonts@TypedTextDatabase@@YAPAPBVFont@touchgfx@@XZ ; TypedTextDatabase::getFonts
	mov	ecx, 4
	imul	edx, ecx, 0
	mov	eax, DWORD PTR [eax+edx]
	jmp	SHORT $LN1@getFont
$LN5@getFont:
; Line 17
	call	?getFonts@TypedTextDatabase@@YAPAPBVFont@touchgfx@@XZ ; TypedTextDatabase::getFonts
	mov	ecx, 4
	shl	ecx, 0
	mov	eax, DWORD PTR [eax+ecx]
	jmp	SHORT $LN1@getFont
$LN6@getFont:
; Line 20
	call	?getFonts@TypedTextDatabase@@YAPAPBVFont@touchgfx@@XZ ; TypedTextDatabase::getFonts
	mov	ecx, 4
	shl	ecx, 1
	mov	eax, DWORD PTR [eax+ecx]
	jmp	SHORT $LN1@getFont
$LN7@getFont:
; Line 23
	call	?getFonts@TypedTextDatabase@@YAPAPBVFont@touchgfx@@XZ ; TypedTextDatabase::getFonts
	mov	ecx, 4
	imul	edx, ecx, 3
	mov	eax, DWORD PTR [eax+edx]
	jmp	SHORT $LN1@getFont
$LN8@getFont:
; Line 26
	call	?getFonts@TypedTextDatabase@@YAPAPBVFont@touchgfx@@XZ ; TypedTextDatabase::getFonts
	mov	ecx, 4
	shl	ecx, 2
	mov	eax, DWORD PTR [eax+ecx]
	jmp	SHORT $LN1@getFont
$LN9@getFont:
; Line 29
	call	?getFonts@TypedTextDatabase@@YAPAPBVFont@touchgfx@@XZ ; TypedTextDatabase::getFonts
	mov	ecx, 4
	imul	edx, ecx, 5
	mov	eax, DWORD PTR [eax+edx]
	jmp	SHORT $LN1@getFont
$LN10@getFont:
; Line 31
	xor	eax, eax
$LN1@getFont:
; Line 33
	pop	edi
	pop	esi
	pop	ebx
	add	esp, 208				; 000000d0H
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	4
$LN12@getFont:
	DD	$LN4@getFont
	DD	$LN5@getFont
	DD	$LN6@getFont
	DD	$LN7@getFont
	DD	$LN8@getFont
	DD	$LN9@getFont
?getFont@ApplicationFontProvider@@UAEPAVFont@touchgfx@@G@Z ENDP ; ApplicationFontProvider::getFont
_TEXT	ENDS
END
