# vim: et ts=2 sw=2

module Cli
  include ConfDirViews

  def add_header(args)
    comp, incl = args.split("=", 2)
    pathstr, typestr = comp.split(".", 2)

    path = pathstr.split("::")
    mod = path[0..-2].join("::")
    comp = path.last

    incl_type =
      if incl.starts_with?("./")
        nil
      else
        :system
      end

    scope =
      case typestr
      when "h"
        :public
      when "cpp"
        :private
      else
        raise ArgumentError.new("Unknown file type #{typestr}")
      end

    if incl_type
      conf_add_comp_includes(incl, mod, comp, incl_type, scope)
    else
      conf_add_comp_includes(incl, mod, comp, scope)
    end
  end

  def list_config
    puts "sms_root: #{conf_sms_root}"
    puts "project_root: #{conf_project_root}"
    puts "== Mods =="
    conf_each_mod do |mod_name, mod_conf|
      puts "  ** #{mod_name}"
      conf_each_comp(mod_name) do |comp_name, comp_conf|
        publics = conf_comp_includes(mod_name, comp_name, :public)
          .map { |incl| "#{incl}" }
        privates = conf_comp_includes(mod_name, comp_name, :private)
          .map { |incl| "(#{incl})" }
        spublics = conf_comp_includes(mod_name, comp_name, :system, :public)
          .map { |incl| "#{incl}" }
        sprivates = conf_comp_includes(mod_name, comp_name, :system, :private)
          .map { |incl| "(#{incl})" }

        includes = [publics, spublics, privates, sprivates]
          .flat_map { |id| id }
          .join(", ")
        puts "    -- #{comp_name}: #{includes}"
      end
    end
  end
end
