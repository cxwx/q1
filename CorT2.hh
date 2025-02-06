/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CorT2.hh                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenxu <chenxu@mail.ustc.edu.cn>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 14:37:39 by chenxu            #+#    #+#             */
/*   Updated: 2024/05/12 17:25:36 by chenxu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// cspell:disable
#ifndef CORSIKAEVTH_HH_
#define CORSIKAEVTH_HH_

#include <TVector3.h>
#include <iostream>
#include "CorT1.hh"
class CorT2 : public CorT1 {
 public:
  CorT2() = default;
  ~CorT2() override = default;
  CorT2(const CorT2&) = default;
  CorT2(CorT2&&) = default;  // TODO(chenxu): check
  CorT2& operator=(const CorT2&) = default;
  CorT2& operator=(CorT2&&) = default;  // TODO(chenxu): check
  [[nodiscard]] inline float evno() const { return geti(1); }
  [[nodiscard]] inline float id() const { return geti(2); }
  [[nodiscard]] inline float e0() const { return geti(3); }
  [[nodiscard]] inline float startAltitude() const { return geti(4); }
  [[nodiscard]] inline int NFirstTargetIfFixed() const { return static_cast<int>(geti(5)); }
  [[nodiscard]] inline float first_intr_p() const { return geti(6); }
  [[nodiscard]] inline float px() const { return geti(7); }
  [[nodiscard]] inline float py() const { return geti(8); }
  [[nodiscard]] inline float pz() const { return geti(9); }
  [[nodiscard]] inline float theta() const { return geti(10); }
  [[nodiscard]] inline float phi() const { return geti(11); }
  [[nodiscard]] inline int NRandomSequences() const { return static_cast<int>(geti(12)); }                                // {max 10}
  [[nodiscard]] inline int seedOfSequence(const int& i, const int& j) { return static_cast<int>(geti(10 + 3 * i + j)); }  // j = 0,1,2
  [[nodiscard]] inline int NOffsetRandom1(const int& i, const int& j) { return static_cast<int>(geti(20 + 3 * i + j)); }  // mod
  [[nodiscard]] inline int NOffsetRandom2(const int& i, const int& j) { return static_cast<int>(geti(30 + 3 * i + j)); }  // /
  [[nodiscard]] inline float runo() const { return geti(43); }
  [[nodiscard]] inline float rundate() const { return geti(44); }
  [[nodiscard]] inline float version() const { return geti(45); }
  [[nodiscard]] inline float numOfObsLevel() const { return geti(46); }
  [[nodiscard]] inline float obsHeight(const int& i) const { return geti(46 + i); }  // {1,2,3...9,10
  [[nodiscard]] inline float slope() const { return geti(57); }
  [[nodiscard]] inline float Elow() const { return geti(58); }   // GeV
  [[nodiscard]] inline float Ehigh() const { return geti(59); }  // GeV
  [[nodiscard]] inline float EKCUThadrons() const { return geti(60); }
  [[nodiscard]] inline float EKCUTmuons() const { return geti(61); }
  [[nodiscard]] inline float EKCUTelecs() const { return geti(62); }
  [[nodiscard]] inline float EKCUTgamma() const { return geti(63); }
  [[nodiscard]] inline int NFLAIN() const { return static_cast<int>(geti(64)); }
  [[nodiscard]] inline int NFLDIF() const { return static_cast<int>(geti(65)); }
  [[nodiscard]] inline int NFLPI0() const { return static_cast<int>(geti(66)); }
  [[nodiscard]] inline int NFLPIF() const { return static_cast<int>(geti(67)); }
  [[nodiscard]] inline int NFLCHE() const { return static_cast<int>(geti(68)); }
  [[nodiscard]] inline int NFRAGM() const { return static_cast<int>(geti(69)); }
  [[nodiscard]] inline float magneticX() const { return geti(70); }  // uT
  [[nodiscard]] inline float magneticZ() const { return geti(71); }
  [[nodiscard]] inline float flagEGS4() const { return geti(72); }
  [[nodiscard]] inline float flagNKG() const { return geti(73); }
  [[nodiscard]] inline float flagLEHad() const { return geti(74); }
  [[nodiscard]] inline float flagHEHad() const { return geti(75); }
  [[nodiscard]] inline float flagCherenkov() const { return geti(76); }
  [[nodiscard]] inline float flagNeutrio() const { return geti(77); }
  [[nodiscard]] inline float flagCurved() const { return geti(78); }
  [[nodiscard]] inline float flagPC() const { return geti(79); }
  [[nodiscard]] inline float thetaLow() const { return geti(80); }
  [[nodiscard]] inline float thetaHigh() const { return geti(81); }
  [[nodiscard]] inline float phiLow() const { return geti(82); }
  [[nodiscard]] inline float phiHigh() const { return geti(83); }
  [[nodiscard]] inline float bunchSizeCherenkov() const { return geti(84); }
  [[nodiscard]] inline int NCherenkovX() const { return static_cast<int>(geti(85)); }
  [[nodiscard]] inline int NCherenkovY() const { return static_cast<int>(geti(86)); }
  [[nodiscard]] inline float gridCherenkovX() const { return geti(87); }
  [[nodiscard]] inline float gridCherenkovY() const { return geti(88); }
  [[nodiscard]] inline float lengthCherenkovX() const { return geti(89); }
  [[nodiscard]] inline float lengthCherenkovY() const { return geti(90); }
  [[nodiscard]] inline float outCherenkovX() const { return geti(91); }
  [[nodiscard]] inline float ARRANG() const { return geti(92); }
  [[nodiscard]] inline float flagMuonAdd() const { return geti(93); }
  [[nodiscard]] inline float stepLengthMultiScatEGS4() const { return geti(94); }
  [[nodiscard]] inline float waveLengthLow() const { return geti(95); }
  [[nodiscard]] inline float waveLengthHigh() const { return geti(96); }
  [[nodiscard]] inline int NCherenkovRsp() const { return static_cast<int>(geti(97)); }
  [[nodiscard]] inline float coreX(const int& i) const { return geti(97 + i); }
  [[nodiscard]] inline float coreY(const int& i) const { return geti(117 + i); }
  [[nodiscard]] inline float flagSIBYLL() const { return geti(138); }
  [[nodiscard]] inline float flagSIBYLLCross() const { return geti(139); }
  [[nodiscard]] inline float flagQGSJET() const { return geti(140); }
  [[nodiscard]] inline float flagQGSJETCross() const { return geti(141); }
  [[nodiscard]] inline float flagDPMJET() const { return geti(142); }
  [[nodiscard]] inline float flagDPMJETCross() const { return geti(143); }
  [[nodiscard]] inline float flagVenusNexusEPOSCross() const { return geti(144); }
  [[nodiscard]] inline float muonMulti() const { return geti(145); }
  [[nodiscard]] inline float NKGRadial() const { return geti(146); }
  [[nodiscard]] inline float EFRCTHN() const { return geti(147); }
  [[nodiscard]] inline float EFRCTHN_THINRAT() const { return geti(148); }
  [[nodiscard]] inline float WMAX() const { return geti(149); }
  [[nodiscard]] inline float WMAX_WEITRAT() const { return geti(150); }
  [[nodiscard]] inline float CORECUT() const { return geti(151); }
  [[nodiscard]] inline float innerAngleVIEWCONE() const { return geti(152); }
  [[nodiscard]] inline float outerAngleVIEWCONE() const { return geti(153); }
  [[nodiscard]] inline float transitionEnergy() const { return geti(154); }
  [[nodiscard]] inline float flagSkim() const { return geti(155); }
  [[nodiscard]] inline float altitude() const { return geti(156); }
  [[nodiscard]] inline float startingHeight() const { return geti(157); }
  [[nodiscard]] inline float flagExpliciteCharm() const { return geti(158); }
  [[nodiscard]] inline float flagHadOrigin() const { return geti(159); }
  [[nodiscard]] inline float minDepthConex() const { return geti(160); }
  [[nodiscard]] inline float highEThreshHad() const { return geti(161); }
  [[nodiscard]] inline float highEThreshMu() const { return geti(162); }
  [[nodiscard]] inline float highEThreshEm() const { return geti(163); }
  [[nodiscard]] inline float lowEThreshHad() const { return geti(164); }
  [[nodiscard]] inline float lowEThreshMu() const { return geti(165); }
  [[nodiscard]] inline float lowEThreshEm() const { return geti(166); }
  [[nodiscard]] inline float CURVOUT() const { return geti(167); }
  [[nodiscard]] inline float whmaxThinHad() const { return geti(168); }
  [[nodiscard]] inline float wtmaxThinEm() const { return geti(169); }
  [[nodiscard]] inline float whmaxSampleHad() const { return geti(170); }
  [[nodiscard]] inline float wtmaxSampleMu() const { return geti(171); }
  [[nodiscard]] inline float wtmaxSampleEm() const { return geti(172); }
  [[nodiscard]] inline float halfWidthAUGERHIT() const { return geti(173); }
  [[nodiscard]] inline float detectorDisAUGERHIT() const { return geti(174); }
  [[nodiscard]] inline float AUGERHIT() const { return geti(175); }
  [[nodiscard]] inline int NMULTITHIN() const { return static_cast<int>(geti(176)); }
  [[nodiscard]] inline float EFracHadThin(const int& j) const { return geti(176 + j); }
  [[nodiscard]] inline float weightLimitHadThin(const int& j) const { return geti(182 + j); }
  [[nodiscard]] inline float EFracEmThin(const int& j) const { return geti(188 + j); }
  [[nodiscard]] inline float weightLimitEmThin(const int& j) const { return geti(194 + j); }
  [[nodiscard]] inline int seedOfSequenceMULTITHIN(const int& i, const int& j) { return static_cast<int>(geti(198 + 3 * i + j)); }  // j = 0,1,2
  [[nodiscard]] inline int NOffsetRandom1MULTITHIN(const int& i, const int& j) { return static_cast<int>(geti(204 + 3 * i + j)); }  // mod
  [[nodiscard]] inline int NOffsetRandom2MULTITHIN(const int& i, const int& j) { return static_cast<int>(geti(210 + 3 * i + j)); }  // /
  [[nodiscard]] inline float threshEICECUBE() const { return geti(219); }
  [[nodiscard]] inline float flagGzipICECUBE() const { return geti(220); }
  [[nodiscard]] inline float flagPipeICECUBE() const { return geti(221); }
  [[nodiscard]] inline float indexMULTITHINCOAST() const { return geti(222); }
  [[nodiscard]] inline float flagOutMULTITHIN() const { return geti(223); }
  [[nodiscard]] inline float XObservation() const { return geti(224); }
  [[nodiscard]] inline float YObservation() const { return geti(225); }
  [[nodiscard]] inline float ZHeight() const { return geti(226); }
  [[nodiscard]] inline float thetaObservation() const { return geti(227); }
  [[nodiscard]] inline float phiObservation() const { return geti(228); }
  [[nodiscard]] inline float depthObservation() const { return geti(229); }

  [[nodiscard]] double t0() const;  // t first init p as light speed
  [[nodiscard]] inline auto pxyz() const { return TVector3(px(), py(), pz()); }

  [[nodiscard]] inline float num() const { return evno(); }

  /* Flawfinder: ignore */
  void read(float* lia) override { read_nothin(lia); }

  // Flawfinder: ignore
  void read(std::istream& in) override { read_nothin(in); }
  void write(std::ostream& out) override { write_nothin(out); }

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winconsistent-missing-override"
  ClassDefOverride(CorT2, 1);  // NOLINT
#pragma clang diagnostic pop
};

std::ostream& operator<<(std::ostream& out, const CorT2&);

#endif  // CORSIKAEVTH_HH_
