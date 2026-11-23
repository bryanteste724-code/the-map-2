~/the-map-2 $ using namespace geode::prelude;         it())
            return false;                                   
        auto menu = static_cast<CCMenu*>(
            this->getNo command using found, did you mean:   Command 2ping in package 2ping                              Command gping in package gping
 Command hping in package hping3 from the root-repo repository
 Command nping in package nmap
 Command ping in package termux-tools
~/the-map-2 $                                               ~/the-map-2 $ class MapImageLayer : public CCLayerColor {
No command class found, did you mean:
 Command clamd in package clamav
 Command clang in package clang
 Command ctags in package ctags
 Command cast in package foundry
 Command jless in package jless
 Command lpass in package lastpass-cli
 Command less in package less                                Command classes in package libgnustep-base
 Command gloss in package mesa-demos from the x11-repo repository
 Command ilasm in package mono
 Command pass in package pass                               ~/the-map-2 $     CCSprite* m_image = nullptr;              CCSprite*: command not found                                ~/the-map-2 $     CCSprite* m_gold = nullptr;               CCSprite*: command not found                                ~/the-map-2 $     CCMenuItemSpriteExtra* m_closeButton = nullptr;
CCMenuItemSpriteExtra*: command not found
~/the-map-2 $     CCPoint m_last;
No command CCPoint found, did you mean:
 Command point in package mesa-demos from the x11-repo repository
 Command SCMPrint in package xerces-c                       ~/the-map-2 $     bool m_dragging = false;
No command bool found, did you mean:                         Command abook in package abook                              Command atool in package atool
 Command babl in package babl
 Command bcal in package bcal
 Command bmon in package bmon
 Command bore in package bore
 Command borg in package borgbackup                          Command brook in package brook
 Command broot in package broot
 Command btop in package btop from the root-repo repository  Command cook in package cookcli
 Command csol in package csol
 Command foot in package foot from the x11-repo repository
 Command hvol in package hfsutils
 Command dbtool in package libnss
 Command moor in package moor                                Command btoa in package nss-utils
 Command ol in package ol
 Command bbox in package texlive-bin
 Command col in package util-linux
 Command wol in package wol                                 ~/the-map-2 $                                               ~/the-map-2 $ public:
public:: command not found                                  ~/the-map-2 $     bool init() override {
bash: syntax error near unexpected token `('
~/the-map-2 $         if (!CCLayerColor::initWithColor({0, 0, 0, 255}))
bash: !CCLayerColor: event not found
~/the-map-2 $             return false;
bash: return: false: numeric argument required
bash: return: can only `return' from a function or sourced script
~/the-map-2 $
~/the-map-2 $         auto win = CCDirector::sharedDirector()->getWinSize();
bash: syntax error near unexpected token `('
ite~/the-map-2 $
:~/the-map-2 $         m_image = CCSprite::create("map.png"_spr);
bash: syntax error near unexpected token `('
~/the-map-2 $         if (!m_image)                         bash: !m_image: event not found
~/the-map-2 $             return false;
bash: return: false: numeric argument required
bash: return: can only `return' from a function or sourced script
~/the-map-2 $
~/the-map-2 $         auto size = m_image->getContentSize();bash: syntax error near unexpected token `('
~/the-map-2 $         m_image->setPosition(win / 2);
bash: syntax error near unexpected token `('
~/the-map-2 $
~/the-map-2 $         constexpr float zoom = 2.45f;
 constexpr: command not found
~/the-map-2 $         m_image->setScaleX((win.width / size.width) * zoom);
bash: syntax error near unexpected token `('
~/the-map-2 $         m_image->setScaleY((win.height / size.height) * zoom);
bash: syntax error near unexpected token `('
~/the-map-2 $
 ~/the-map-2 $         addChild(m_image);
(bash: syntax error near unexpected token `m_image'
~/the-map-2 $
{~/the-map-2 $         // GOLD
pbash: //: Is a directory                                   ~/the-map-2 $         m_gold = CCSprite::create("gold - the map.png"_spr);
bash: syntax error near unexpected token `('                ~/the-map-2 $
 ~/the-map-2 $         if (m_gold) {
abash: syntax error near unexpected token `{'               ~/the-map-2 $             m_gold->setScale(0.5f);
 bash: syntax error near unexpected token `('
~/the-map-2 $             m_gold->setPosition({
bash: syntax error near unexpected token `('                M~/the-map-2 $                 win.width / 2,
     auto lawin.width: command not found
~/the-map-2 $                 win.height - 20
win.height: command not found                               ~/the-map-2 $             });
bash: syntax error near unexpected token `}'
~/the-map-2 $             addChild(m_gold, 50);
bash: syntax error near unexpected token `m_gold,'
~/the-map-2 $         }                                     bash: syntax error near unexpected token `}'
~/the-map-2 $                                               
~/the-map-2 $         auto closeSprite = CCSprite::create("GJ_closeBtn_001.png"_spr);
bash: syntax error near unexpected token `('                 ~/the-map-2 $         if (!closeSprite)
bash: !closeSprite: event not found
~/the-map-2 $             return false;
                      autobash: return: false: numeric argument required
bash: return: can only `return' from a function or sourced script
~/the-map-2 $
 ~/the-map-2 $         m_closeButton = CCMenuItemSpriteExtra::create(
bash: syntax error near unexpected token `('
~/the-map-2 $             closeSprite,                        closeSprite,: command not found
~/the-map-2 $             this,
No command this, found, did you mean:
 Command ciso in package ciso
 Command tail in package coreutils
 Command host in package dnsutils
 Command elisa in package elisa from the x11-repo repository
 Command tsh in package etsh
 Command fdisk in package fdisk
 Command fish in package fish
 Command chisel in package foundry
 Command tadsc in package frobtads
 Command tsc in package gotify                               Command gdisk in package gptfdisk from the root-repo repository                                                         Command tlsa in package hash-slinger
 Command hls in package hfsutils
 Command khost in package knot-utils
 Command klist in package krb5
 Command noise in package mesa-demos from the x11-repo repository
 Command mise in package mise
 Command ts in package moreutils
 Command tabs in package ncurses-utils
 Command dist in package nmh
 Command alist in package openlist
 Command trust in package p11-kit
 Command rhash in package rhash
 Command chpst in package runit
 Command tsp in package task-spooler
 Command task in package taskwarrior
 Command tclsh in package tcl
 Command tcsh in package tcsh
 Command tsh in package teleport-tsh
 Command chsh in package termux-tools
 Command tie in package texlive-bin
 Command tidy in package tidy
 Command tig in package tig
 Command time in package time                                Command timg in package timg
 Command wish in package tk
 Command trzsz in package trzsz-go
 Command tssh in package trzsz-ssh
 Command tspsi in package tsduck-tools
 Command tsu in package tsu
 Command tjs in package txikijs
 Command typst in package typst
 Command vis in package vis
 Command which in package which
 Command whois in package whois
 Command xhs in package xh                                   Command xhost in package xorg-xhost from the x11-repo repository
~/the-map-2 $             menu_selector(MapImageLayer::onClose)
bash: syntax error near unexpected token `MapImageLayer::onClose'                                                       ~/the-map-2 $         );
bash: syntax error near unexpected token `)'
~/the-map-2 $
~/the-map-2 $         auto menu = CCMenu::create(m_closeButton, nullptr);
bash: syntax error near unexpected token `('
~/the-map-2 $         menu->setPosition(CCPointZero);
bash: syntax error near unexpected token `('
~/the-map-2 $
~/the-map-2 $         m_closeButton->setPosition({
bash: syntax error near unexpected token `('
~/the-map-2 $             win.width - 25,
win.width: command not found
~/the-map-2 $             win.height - 25
win.height: command not found
~/the-map-2 $         });
bash: syntax error near unexpected token `}'
~/the-map-2 $
~/the-map-2 $         addChild(menu, 100);
bash: syntax error near unexpected token `menu,'
~/the-map-2 $
~/the-map-2 $         setTouchEnabled(true);
bash: syntax error near unexpected token `true'
~/the-map-2 $         setKeypadEnabled(true);
bash: syntax error near unexpected token `true'
~/the-map-2 $
~/the-map-2 $         return true;
bash: return: true: numeric argument required
bash: return: can only `return' f
